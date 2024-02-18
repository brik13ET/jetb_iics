import Native.Socket;

public class Client {
    
    public static void print16(byte[] buf)
    {
        int i = 0;
        for(;i < buf.length; i++)
        {
            System.out.printf("\n%04x:\t", i);
            for( ;i < buf.length && ((i + 1) % 16 != 0); i++)
                System.out.printf("%02X ", buf[i]);
        }
        System.out.printf("\n");
    }
    public static void main(String[] args) {
        Socket.init("lo");
        Socket.sendTo("Быстров Михаил Артёмович".getBytes());
        byte[] recv = Socket.recvFrom("Data accepted".getBytes(), 42);
        System.out.printf("Get data %d bytes\n", recv.length);
        print16(recv);
        Socket.deinit();
    }
}