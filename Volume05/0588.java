
/**
 * 0588 Simple Calculator
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input;
        int result = Integer.parseInt(br.readLine());

        while (!(input = br.readLine()).equals("=")) {
            int n = Integer.parseInt(br.readLine());

            switch (input) {
            case "+":
                result += n;
                break;
            case "-":
                result -= n;
                break;
            case "*":
                result *= n;
                break;
            case "/":
                result /= n;
                break;
            }

        }

        System.out.println(result);
    }
}