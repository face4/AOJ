
/**
 * 0044 Prime Number II
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean[] nonPrime = new boolean[50022]; // default false, 50021 is prime number

        for (int i = 2; i <= 25011; i++) {
            if (nonPrime[i])
                continue;

            for (int j = i + i; j <= 50021; j += i) {
                nonPrime[j] = true;
            }
        }

        String line;
        while ((line = br.readLine()) != null) {
            int num = Integer.parseInt(line);
            int tmp = num;
            while (nonPrime[--tmp]) {
            }
            System.out.print(tmp + " ");
            tmp = num;
            while (nonPrime[++tmp]) {
            }
            System.out.println(tmp);
        }

    }
}