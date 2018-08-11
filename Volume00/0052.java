
/**
 * 0052 Factorial II
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 1-origin index0は使わない
        int[] five = new int[20001];
        int[] two = new int[20001];

        for (int i = 5; i <= 20000; i *= 5) {
            for (int j = i; j <= 20000; j += i) {
                five[j]++;
            }
        }

        for (int i = 2; i <= 20000; i *= 2) {
            for (int j = i; j <= 20000; j += i) {
                two[j]++;
            }
        }

        String line;

        while (!(line = br.readLine()).equals("0")) {
            int n = Integer.parseInt(line);

            int twoNum = 0;
            int fiveNum = 0;

            for (int i = 0; i <= n; i++) {
                twoNum += two[i];
                fiveNum += five[i];
            }

            System.out.println(Math.min(twoNum, fiveNum));
        }
    }
}