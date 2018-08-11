
/**
 * 0021-Parallerism
 */

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for (int j = 0; j < n; j++) {
            String[] input = br.readLine().split(" ");

            double p1x = Double.parseDouble(input[2]) - Double.parseDouble(input[0]);
            double p1y = Double.parseDouble(input[3]) - Double.parseDouble(input[1]);

            double p2x = Double.parseDouble(input[6]) - Double.parseDouble(input[4]);
            double p2y = Double.parseDouble(input[7]) - Double.parseDouble(input[5]);

            // 外積が1.0^-10(各値はそれぞれ小数点第5位まで、その積の誤差は小数点第10位まで考慮すればOK?)より小さい <=> 平行
            if (Math.abs(p1x * p2y - p1y * p2x) < 1.0e-10) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}