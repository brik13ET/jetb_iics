package Native;

public class Socket {

    static {
        System.loadLibrary("iics_4");
    }
    public static native int init(String int_name);
    public static native int send(byte[] data);
    public static native int recv(byte[] data, int offset);
    public static native int close();
}
