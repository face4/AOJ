
/**
 * 0107 Carry a Cheese
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while (!(line = br.readLine()).equals("0 0 0")) {
            String[] input = line.split(" ");

            int d = Integer.parseInt(input[0]);
            int w = Integer.parseInt(input[1]);
            int h = Integer.parseInt(input[2]);

            double diagonal = Math.min(Math.sqrt(d * d + w * w), Math.sqrt(w * w + h * h));
            diagonal = Math.min(diagonal, Math.sqrt(h * h + d * d));

            int n = Integer.parseInt(br.readLine());

            for (int i = 0; i < n; i++) {
                int r = Integer.parseInt(br.readLine());
                if (diagonal < r * 2) {
                    System.out.println("OK");
                } else {
                    System.out.println("NA");
                }
            }
        }

    }
}