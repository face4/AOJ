
/**
 * 0641 Pencils
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int n = Integer.parseInt(input[0]);
        int a = Integer.parseInt(input[1]);
        int b = Integer.parseInt(input[2]);
        int c = Integer.parseInt(input[3]);
        int d = Integer.parseInt(input[4]);

        System.out.println(Math.min(n / a * b + (n % a == 0 ? 0 : b), n / c * d + (n % c == 0 ? 0 : d)));

    }
}