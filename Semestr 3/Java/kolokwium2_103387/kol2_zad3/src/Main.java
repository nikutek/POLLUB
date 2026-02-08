import java.io.*;
import java.net.Socket;

public class Main {
    public static void main(String[] args) throws Exception {
        Socket s = new Socket("example.com", 80);

        BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
        PrintWriter out = new PrintWriter(s.getOutputStream());

        out.print("GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n");
        out.flush();

        Thread watek = new Thread(() -> {
            try {
                String l;
                while ((l = in.readLine()) != null) {
                    System.out.println(l);
                }
            } catch (IOException e) {}
        });

        watek.start();
        watek.join();

        s.close();
        System.out.println("Rozłączono i zakończono program");
    }
}