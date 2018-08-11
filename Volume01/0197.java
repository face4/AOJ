
/**
 * 0197 Greatest Common Divisor: Euclidean Algorithm
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
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            if (x < y) {
                int tmp = x;
                x = y;
                y = tmp;
            }

            int step = 0;
            do {
                x = x % y;
                int tmp = x;
                x = y;
                y = tmp;
                step++;
            } while (y != 0);

            System.out.println(x + " " + step);
        }
    }
}