// http://www.sousakuba.com/Programming/gs_hittest_point_triangle.html
// 外積によるベクトルが3つとも同じ方向を向けば点は三角形の内部にある

/**
 * 0012 A Point in a Triangle
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

            double x1 = Double.parseDouble(input[0]);
            double y1 = Double.parseDouble(input[1]);
            double x2 = Double.parseDouble(input[2]);
            double y2 = Double.parseDouble(input[3]);
            double x3 = Double.parseDouble(input[4]);
            double y3 = Double.parseDouble(input[5]);
            double xp = Double.parseDouble(input[6]);
            double yp = Double.parseDouble(input[7]);

            double z1 = (x2 - x1) * (yp - y2) - (y2 - y1) * (xp - x2);
            double z2 = (x3 - x2) * (yp - y3) - (y3 - y2) * (xp - x3);
            double z3 = (x1 - x3) * (yp - y1) - (y1 - y3) * (xp - x1);

            if ((z1 > 0 && z2 > 0 && z3 > 0) || (z1 < 0 && z2 < 0 && z3 < 0)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}