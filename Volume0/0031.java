
/**
 * 0031 Weight
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input;

        while ((input = br.readLine()) != null) {
            StringBuilder result = new StringBuilder();
            int n = Integer.parseInt(Integer.toBinaryString(Integer.parseInt(input)));
            int weight = 1;
            while (n != 0) {
                if (n % 10 == 1) {
                    result.append(weight + " ");
                }
                n /= 10;
                weight *= 2;
            }
            System.out.println(result.substring(0,result.length()-1));
        }

    }
}