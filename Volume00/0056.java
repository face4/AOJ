
/**
 * 0056 Goldbach's Conjecture
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean[] nonPrime = new boolean[50001];
        nonPrime[0] = true;
        nonPrime[1] = true;

        for (int i = 2; i <= 25000; i++) {
            if (nonPrime[i]) {
                continue;
            }

            for (int j = i + i; j <= 50000; j += i) {
                nonPrime[j] = true;
            }
        }

        String line;
        while (!(line = br.readLine()).equals("0")) {
            int x = Integer.parseInt(line);
            int result = 0;

            if (x % 2 == 0) {
                for (int j = 2; j <= x / 2; j++) {
                    if (!nonPrime[j] && !nonPrime[x - j])
                        result++;
                }
            } else {
                if (!nonPrime[x - 2])
                    result++;
            }

            System.out.println(result);
        }
    }
}