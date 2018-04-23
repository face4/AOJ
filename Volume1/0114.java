// time limit exceeded
/**
 * 0114 Electro-Fly
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (!(line = br.readLine()).equals("0 0 0 0 0 0")) {
            String[] input = line.split(" ");

            int a1 = Integer.parseInt(input[0]);
            int m1 = Integer.parseInt(input[1]);
            int a2 = Integer.parseInt(input[2]);
            int m2 = Integer.parseInt(input[3]);
            int a3 = Integer.parseInt(input[4]);
            int m3 = Integer.parseInt(input[5]);

            int x = 1;
            int y = 1;
            int z = 1;

            int counter = 0;

            do {
                x = (a1 * x) % m1;
                y = (a2 * y) % m2;
                z = (a3 * z) % m3;
                counter++;
            } while ((x + y + z) != 3);

            System.out.println(counter);
        }

    }
}