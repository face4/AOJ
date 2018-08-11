
/**
 * 0079 Area of Polygon
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static double calcArea(double x1, double y1, double x2, double y2, double x3, double y3) {
        double a = Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        double b = Math.sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        double c = Math.sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        double z = (a + b + c) / 2;

        return Math.sqrt(z * (z - a) * (z - b) * (z - c));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(",");
        double x1 = Double.parseDouble(s[0]);
        double y1 = Double.parseDouble(s[1]);
        double area = 0;

        s = br.readLine().split(",");
        double befx = Double.parseDouble(s[0]);
        double befy = Double.parseDouble(s[1]);

        String line;
        while ((line = br.readLine()) != null) {
            String[] second = line.split(",");
            double nowx = Double.parseDouble(second[0]);
            double nowy = Double.parseDouble(second[1]);

            area += calcArea(x1, y1, befx, befy, nowx, nowy);

            befx = nowx;
            befy = nowy;
        }

        System.out.printf("%.6f%n", area);
    }
}