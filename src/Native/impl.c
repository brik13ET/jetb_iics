#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>           // close()
#include <string.h>           // strcpy, memset(), and memcpy()
#include <netdb.h>            // struct addrinfo
#include <sys/types.h>        // needed for socket(), uint8_t, uint16_t, uint32_t
#include <sys/socket.h>       // needed for socket()
#include <netinet/in.h>       // IPPROTO_ICMP, INET_ADDRSTRLEN
#include <netinet/ip.h>       // struct ip and IP_MAXPACKET (which is 65535)
#include <netinet/ether.h>
#include <netinet/udp.h>
#include <arpa/inet.h>        // inet_pton() and inet_ntop()
#include <sys/ioctl.h>        // macro ioctl is defined
#include <bits/ioctls.h>      // defines values for argument "request" of ioctl.
#include <net/if.h>           // struct ifreq
#include <linux/if_ether.h>   // ETH_P_IP = 0x0800, ETH_P_IPV6 = 0x86DD
#include <linux/if_packet.h>  // struct sockaddr_ll (see man 7 packet)
#include <net/ethernet.h>

#include "Native_Socket.h"

JNIEXPORT jint JNICALL Java_Native_Socket_init  (JNIEnv * env, jclass jclass1, jstring jstring1)
{
    jboolean isCopy = false;
    char* data = (*env)->GetStringUTFChars(env, jstring1, &isCopy);
    printf( "%s call: %s\n", __func__, data);
    (*env)->ReleaseStringUTFChars(env, jstring1, data);
	return 0;
}

JNIEXPORT jint JNICALL Java_Native_Socket_send  (JNIEnv * env, jclass jclass1, jstring jstring1)
{
	return 0;
}

JNIEXPORT jint JNICALL Java_Native_Socket_recv  (JNIEnv * env, jclass jclass1, jbyteArray array, jint jint1)
{
	return 0;
}

JNIEXPORT jint JNICALL Java_Native_Socket_close (JNIEnv * env, jclass jclass1)
{
	return 0;
}