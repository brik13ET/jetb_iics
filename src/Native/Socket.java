package Native;

public class Socket {

    static {
        System.loadLibrary("iics_4");
    }
/**

- инициализирует работу с "сырыми" сокетами.
interfaceName - имя интерфейса, который необходимо задействовать для работы (например "eth0")
Возвращает true, если инициализация прошла успешно, иначе false.
 */
public static native boolean init(String interfaceName);

/**

- завершает работу с сырыми сокетами, возвращает используюмую
память системе.
 */
public static native void deinit();

/**

- отсылает через сырые сокеты буфер buf.
Возвращает количество посланных байт, или -1 при ошибке.
 */
public static native int sendTo(byte[] buf);

/**

- прием первого пакета, содержимое
которого совпадает с buf со смещения offset. Возвращает массив присланных байт.
 */
public static native byte[] recvFrom(byte[] buf, int offset);
}
