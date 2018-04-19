
/**
 * NTL_1_D Euler's Phi Function
 * 
 * 参考 : http://yoshiiz.blog129.fc2.com/blog-entry-410.html
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int result = n;
        int soinshi = 2;

        if (n % soinshi == 0) {
            result /= soinshi;
            do {
                n /= soinshi;
            } while (n % soinshi == 0);
        }

        soinshi = 3;
        while (soinshi <= (n / soinshi)) {
            if (n % soinshi == 0) {
                result = result / soinshi * (soinshi - 1);
                do {
                    n /= soinshi;
                } while (n % soinshi == 0);
            }
            soinshi += 2;
        }

        if (n > 1) {
            result = result / n * (n - 1) ;
        }

        System.out.println(result);
    }
}