#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>           // strcpy, memset(), and memcpy()
#include <unistd.h>           // close()
#include <linux/if_ether.h>   // ETH_P_IP = 0x0800, ETH_P_IPV6 = 0x86DD
#include <linux/if_packet.h>  // struct sockaddr_ll (see man 7 packet)
#include <netdb.h>            // struct addrinfo
#include <sys/types.h>        // needed for socket(), uint8_t, uint16_t, uint32_t
#include <sys/socket.h>       // needed for socket()
#include <sys/ioctl.h>        // macro ioctl is defined
#include <net/if.h>           // struct ifreq
#include <net/ethernet.h>
#include <netinet/in.h>       // IPPROTO_ICMP, INET_ADDRSTRLEN
#include <netinet/ip.h>       // struct ip and IP_MAXPACKET (which is 65535)
#include <netinet/if_ether.h>
#include <netinet/udp.h>
#include <arpa/inet.h>        // inet_pton() and inet_ntop()
#include <bits/ioctls.h>      // defines values for argument "request" of ioctl.
#include <errno.h>


#include "Native_Socket.h"

struct sockaddr_ll sockaddrLl;
int sockd;
int fd;

uint16_t checksum(uint8_t *buf, int len){

  if( len % 2 == 1 ){
	buf[len] = 0;
	len++;
  }

  uint16_t *addr = (uint16_t *) buf;
  int count = len;
  register uint32_t sum = 0;
  uint16_t answer = 0;
  // Sum up 2-byte values until none or only one byte left.
  while (count > 1)
  {
	sum += *(addr++);
	count -= 2;
  }

  // Add left-over byte, if any.
  if (count > 0)
  {
	sum += *(uint8_t *) addr;
  }

  // Fold 32-bit sum into 16 bits; we lose information by doing this,
  // increasing the chances of a collision.
  // sum = (lower 16 bits) + (upper 16 bits shifted right 16 bits)
  while (sum >> 16)
  {
	sum = (sum & 0xffff) + (sum >> 16);
  }

  // Checksum is one's compliment of sum.
  answer = ~sum;

  return (answer);
}


JNIEXPORT jboolean JNICALL Java_Native_Socket_init(JNIEnv *env, jclass jclass1, jstring jstring1)
{

	size_t iface_siz = (*env)->GetStringUTFLength(env, jstring1);
	if (iface_siz > IFNAMSIZ)
		return 0;
	jboolean isCopy = false;
	const char *data = (*env)->GetStringUTFChars(env, jstring1, &isCopy);
	sockaddrLl = (struct sockaddr_ll)
			{
					.sll_family = AF_PACKET,
					.sll_protocol = ETH_P_ALL,
					.sll_ifindex = if_nametoindex(data),
					.sll_hatype = ARPHRD_RAWIP,
					.sll_pkttype = PACKET_HOST,
					.sll_halen = 6,
					.sll_addr = {0}
			};
	sockd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if (sockd < 0)
	{
		char buf[40] = {0};
		printf("%s,%d:\terrno: %d\n", __FILE__, __LINE__ - 3, errno);
	}
	(*env)->ReleaseStringUTFChars(env, jstring1, data);
	return JNI_FALSE;
}

JNIEXPORT jint JNICALL Java_Native_Socket_sendTo(JNIEnv *env, jclass jclass1, jbyteArray data)
{
	uint16_t len = (*env)->GetArrayLength(env, data);
	void* buf = malloc(sizeof(struct ether_header) + sizeof(struct ip) + sizeof(struct udphdr) + len);
	
	struct ether_header*	buf_eth	= buf + 0;
	struct ip*				buf_ip	= buf + sizeof(struct ether_header);
	struct udphdr*			buf_udp	= buf + sizeof(struct ether_header) + sizeof(struct ip);
	void*					buf_dat	= buf + sizeof(struct ether_header) + sizeof(struct ip) + sizeof(struct udphdr);

	memcpy(&(buf_eth->ether_dhost), (uint8_t[]){0,0,0,0,0,0}, 6);
	memcpy(&(buf_eth->ether_shost), (uint8_t[]){0,0,0,0,0,0}, 6);
	buf_eth->ether_type = htons(0x0800);

	buf_ip->ip_v   = 4;
	buf_ip->ip_hl  = 5;
	buf_ip->ip_tos = 0;
	buf_ip->ip_len = htons(28 + len);
	buf_ip->ip_id  = htons(0x1234);
	buf_ip->ip_off = htons(IP_DF) ;
	buf_ip->ip_ttl = 120;
	buf_ip->ip_p   = 17; // udp
	buf_ip->ip_sum = 0;
	inet_aton("127.0.0.1", &buf_ip->ip_src);
	inet_aton("127.0.0.1", &buf_ip->ip_dst);

	buf_udp->uh_sport = htons(43521);
	buf_udp->uh_dport = htons(43521);
	buf_udp->uh_ulen  = htons(sizeof(struct udphdr) + len);
	buf_udp->uh_sum   = 0;

	buf_udp->uh_sum= checksum((void*)buf_udp, sizeof(struct udphdr) + len);
	buf_ip->ip_sum = checksum((void*)buf_ip, sizeof(struct ip) + sizeof(struct udphdr) + len);

	void* jbuf = (*env)->GetByteArrayElements(env, data, NULL);
	memcpy(buf_dat, jbuf, len);
	struct sockaddr_ll sockadr_to = sockaddrLl; 
	sendto(
		sockd,
		buf,
		sizeof(struct ether_header) + sizeof(struct ip) + sizeof(struct udphdr) + len,
		MSG_CONFIRM,
		(struct sockaddr*)&sockadr_to,
		sizeof(sockadr_to)
	);
	(*env)->ReleaseByteArrayElements(env, data, jbuf, 0);
	free(buf);
	return 0;
}

JNIEXPORT jbyteArray JNICALL Java_Native_Socket_recvFrom  (JNIEnv * env, jclass clazz, jbyteArray data, jint offset)
{
	struct sockaddr_ll sockadr_from = sockaddrLl;
	socklen_t sl = sizeof(sockaddrLl);
	uint8_t buf_inp[200]; // MTU 1500, but expected data size < 200
	void* jbuf = (*env)->GetByteArrayElements(env, data, NULL);
	uint16_t len = (*env)->GetArrayLength(env, data);
	uint16_t siz;
	do
	{
		siz = recvfrom(sockd, buf_inp, sizeof(buf_inp), 0, (struct sockaddr*)&sockadr_from, &sl);
	} while (memcmp(buf_inp + offset, jbuf, len) && memcmp(&sockadr_from, &sockaddrLl, sizeof(sockaddrLl)));
	(*env)->ReleaseByteArrayElements(env, data, jbuf, 0);

	jbyteArray ret = (*env)->NewByteArray(env, siz);
	(*env)->SetByteArrayRegion(env, ret, 0, siz, buf_inp);
	return ret;
}

JNIEXPORT void JNICALL Java_Native_Socket_deinit(JNIEnv *env, jclass jclass1)
{
	close(sockd);
}
