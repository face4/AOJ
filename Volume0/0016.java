
/**
 * 0016 Treasure Hunt
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        double x = 0.0;
        double y = 0.0;
        int dir = 90;

        while (true) {
            String[] input = br.readLine().split(",");
            if (input[0].equals(input[1]) && input[0].equals("0")) {
                break;
            }

            int distance = Integer.parseInt(input[0]);
            int rotate = Integer.parseInt(input[1]);

            x += Math.cos(dir / 180.0 * Math.PI) * distance;
            y += Math.sin(dir / 180.0 * Math.PI) * distance;
            dir -= rotate;
        }

        Double xx = new Double(x);
        Double yy = new Double(y);

        System.out.printf("%d%n%d%n", xx.intValue(), yy.intValue());
    }
}