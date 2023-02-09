import java.net.*;
import java.io.*;

public class TCP_Client {
    public static void main(String[] args) throws Exception {
        Socket sock = new Socket("127.0.0.1", 4000);
        System.out.println("Enter the file name:\n");

        BufferedReader nameRead = new BufferedReader(new InputStreamReader(System.in));
        String fname = nameRead.readLine();
        PrintWriter pwrite = new PrintWriter(sock.getOutputStream(), true);
        pwrite.println(fname);

        BufferedReader contentRead = new BufferedReader(new InputStreamReader(sock.getInputStream()));
        String str;
        while ((str = contentRead.readLine()) != null) {
            System.out.println(str);
        }
        contentRead.close();
        pwrite.close();
        sock.close();
        nameRead.close();
    }
}