
/**
 * 0538 Shopping
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        int m = Integer.parseInt(input[0]);
        int f = Integer.parseInt(input[1]);
        int b = Integer.parseInt(input[2]);

        if (m + f < b) {
            System.out.println("NA");
        } else {
            System.out.println(m > b ? 0 : b - m);
        }
    }
}