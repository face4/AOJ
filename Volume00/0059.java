// なんか書いたら通っちゃったけど、雑に実装したのでよくわかってない
/**
 * 0059 Intersection of Rectangles
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            String[] input = line.split(" ");

            double xa1 = Double.parseDouble(input[0]);
            double ya1 = Double.parseDouble(input[1]);
            double xa2 = Double.parseDouble(input[2]);
            double ya2 = Double.parseDouble(input[3]);
            double xb1 = Double.parseDouble(input[4]);
            double yb1 = Double.parseDouble(input[5]);
            double xb2 = Double.parseDouble(input[6]);
            double yb2 = Double.parseDouble(input[7]);

            boolean result = true;
            if (xa1 > xb2)
                result = false;
            if (xb1 > xa2)
                result = false;
            if (yb1 > ya2)
                result = false;
            if (ya1 > yb2)
                result = false;

            if (result) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}