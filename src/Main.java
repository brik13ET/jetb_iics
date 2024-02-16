import Native.Socket;

public class Main {
    public static void main(String[] args) {
        Socket.init("lo");
        Socket.send("asdf".getBytes());
        Socket.recv("ASDF".getBytes(), 35);
        Socket.close();
        System.out.println("Hello world!");
    }
}