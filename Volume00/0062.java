
/**
 * 0062 What is the Bottommost?
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        char[] input = new char[10];
        int[] number = new int[10];
        while ((line = br.readLine()) != null) {
            input = line.toCharArray();
            for (int i = 0; i < 10; i++) {
                number[i] = (int) (input[i] - '0');
            }

            for (int i = 0; i < 9; i++) {
                for (int j = 1; j < 10 - i; j++) {
                    number[j - 1] = (number[j - 1] + number[j]) % 10;
                }
            }

            System.out.println(number[0]);
        }
    }
}