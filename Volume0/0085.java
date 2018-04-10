
/**
 * 0085 Joseph's Potato
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (!(line = br.readLine()).equals("0 0")) {
            String[] input = line.split(" ");
            int n = Integer.parseInt(input[0]);
            int m = Integer.parseInt(input[1]);
            boolean[] away = new boolean[n];
            int potato = n - 1;

            for (int i = 0; i < n - 1; i++) {
                int counter = 0;
                while (counter != m) {
                    potato = (potato + 1) % n;
                    if (!away[potato]) {
                        counter++;
                    }
                }
                away[potato] = true;
            }

            for (int i = 0; i < n; i++) {
                if (!away[i]) {
                    System.out.println((i + 1));
                    break;
                }
            }
            
        }
    }
}