
/**
 * 0051 Differential II
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            int now = Integer.parseInt(br.readLine());
            int[] arr = new int[8];
            for (int j = 0; j < 8; j++) {
                arr[j] = now % 10;
                now /= 10;
            }
            Arrays.sort(arr);

            int down = 10000000;
            int up = 1;

            int bigger = 0;
            int smaller = 0;

            for (int j = 0; j < 8; j++) {
                bigger += up * arr[j];
                smaller += down * arr[j];

                down /= 10;
                up *= 10;
            }

            System.out.println((bigger - smaller));
        }
    }
}