
/**
 * 0054 Sum of Nth decimal places
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            String[] input = line.split(" ");
            int s = 0;
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            int n = Integer.parseInt(input[2]);

            int q = a;
            q -= (q / b) * b;

            for (int i = 0; i < n; i++) {
                s += (q * 10) / b;
                q = (q * 10) % b;
                if (q == 0)
                    break;
            }

            System.out.println(s);
        }
    }
}