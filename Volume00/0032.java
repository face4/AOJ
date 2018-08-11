// !!Wrong Answer!!
/**
 * 0032 Plastic Board 
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input;

        int square = 0;
        int diamond = 0;

        while ((input = br.readLine()) != null) {
            String[] line = input.split(",");
            int a = Integer.parseInt(line[0]);
            int b = Integer.parseInt(line[1]);
            int c = Integer.parseInt(line[2]);

            if (c * c + a * a == b * b || c * c + b * b == a * a || a + b <= c || b + c <= a || c + a <= b) {
                continue;
            }

            if (a * a + b * b == c * c) {
                square++;
            }
            if(a == b){
                diamond++;
            }
        }

        System.out.println(square);
        System.out.println(diamond);
    }
}