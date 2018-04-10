
/**
 * 0080 Third Root
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (!(line = br.readLine()).equals("-1")) {
            int q = Integer.parseInt(line);
            double x = q / 2.0;

            while (Math.abs(Math.pow(x, 3.0) - q) >= 0.00001 * q) {
                x = x - (Math.pow(x, 3.0) - q) / 3 / Math.pow(x, 2.0);
            }

            System.out.printf("%.6f%n", x);
        }
    }
}