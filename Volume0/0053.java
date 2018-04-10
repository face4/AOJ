// 素数を10000個求める

/**
 * 0053 Sum of Prime Numbers
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] sum = new int[10001];
        int number = 1;

        for (int i = 1; i <= 10000; i++) {
            while (!isPrime(++number))
                ;

            sum[i] = number + sum[i - 1];
        }

        String line;
        while (!(line = br.readLine()).equals("0")) {
            System.out.println(sum[Integer.parseInt(line)]);
        }

    }

    static boolean isPrime(int n) {
        for (int i = 2; i <= (int) (Math.sqrt(n)); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}