
/**
 * 0074 Videotape
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static String conversion(int a) {
        StringBuilder sb = new StringBuilder();

        int t = a / 3600;
        sb.append("0" + t + ":");
        a -= t * 3600;

        int h = a / 60;
        if (h < 10)
            sb.append("0");
        sb.append(h + ":");
        a -= h * 60;

        if (a < 10)
            sb.append("0");
        sb.append(a);

        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (!(line = br.readLine()).equals("-1 -1 -1")) {
            String[] ths = line.split(" ");
            int T = Integer.parseInt(ths[0]);
            int H = Integer.parseInt(ths[1]);
            int S = Integer.parseInt(ths[2]);
            int seconds = 7200 - 3600 * T - 60 * H - S;
            System.out.println(conversion(seconds));
            System.out.println(conversion(seconds * 3));
        }

    }
}