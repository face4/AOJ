
/**
 * 0010-Circumscribed Circle of a Triangle 
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");

            double x1 = Double.parseDouble(input[0]);
            double y1 = Double.parseDouble(input[1]);
            double x2 = Double.parseDouble(input[2]);
            double y2 = Double.parseDouble(input[3]);
            double x3 = Double.parseDouble(input[4]);
            double y3 = Double.parseDouble(input[5]);

            double A = x2 - x1;
            double B = y2 - y1;
            double p = (y2 * y2 - y1 * y1 + x2 * x2 - x1 * x1) / 2;
            double C = x3 - x1;
            double D = y3 - y1;
            double q = (y3 * y3 - y1 * y1 + x3 * x3 - x1 * x1) / 2;

            double X = (D * p - B * q) / (A * D - B * C);
            double Y = (A * q - C * p) / (A * D - B * C);

            double r = Math.sqrt(Math.pow(X - x1, 2.0) + Math.pow(Y - y1, 2.0));

            System.out.printf("%.3f %.3f %.3f%n", X, Y, r);
        }
    }
}