
/**
 * NTL_1_A Prime Factorize
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        StringBuilder result = new StringBuilder();
        result.append(n + ":");

        int i;
        while (n != 1) {
            for (i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    result.append(" " + i);
                    n /= i;
                    break;
                }
            }

            if (i * i > n) {
                result.append(" " + n);
                break;
            }
        }

        System.out.println(result.toString());
    }
}