import Native.Socket;
import java.io.UnsupportedEncodingException;
public class Server
{
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
    public static void main(String[] args) throws UnsupportedEncodingException
    {
        Socket.init("lo");
        byte[] recv = Socket.recvFrom("Быстров Михаил Артёмович".getBytes(), 42);
        System.out.printf("Get data %d bytes\n", recv.length);
        print16(recv);
        String recvStr = String.format("Data accepted \"%s\"", new String(recv, "UTF-8" ));
        Socket.sendTo(recvStr.getBytes());
        Socket.deinit();
    }
}