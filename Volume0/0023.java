
/**
 * 0023 Circles Intersection
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");

            double xa = Double.parseDouble(input[0]);
            double ya = Double.parseDouble(input[1]);
            double ra = Double.parseDouble(input[2]);
            double xb = Double.parseDouble(input[3]);
            double yb = Double.parseDouble(input[4]);
            double rb = Double.parseDouble(input[5]);

            double distance = Math.sqrt(Math.pow(xb - xa, 2.0) + Math.pow(yb - ya, 2.0));

            if (distance > ra + rb) {
                System.out.println("0");
            } else if (distance < ra - rb) {
                System.out.println("2");
            } else if (distance < rb - ra) {
                System.out.println("-2");
            } else {
                System.out.println("1");
            }
        }
    }
}