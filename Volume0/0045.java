
/**
 * 0045 Sum and Average
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int sum = 0;
        int num = 0;
        int count = 0;

        String line;

        while ((line = br.readLine()) != null) {
            count++;
            String[] input = line.split(",");

            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);

            sum += a * b;
            num += b;
        }

        System.out.println(sum);
        System.out.println((int) ((double) num / count + 0.5));
    }
}