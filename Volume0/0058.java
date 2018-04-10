
/**
 * 0058 Orthogonal
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
            double[] d = new double[8];
            for (int i = 0; i < 8; i++) {
                d[i] = Double.parseDouble(input[i]);
            }

            // (d[3]-d[1])*(d[7]-d[5]) == -1 * (d[2]-d[0]) * (d[6]-d[4])
            if (Math.abs((d[3] - d[1]) * (d[7] - d[5]) + (d[2] - d[0]) * (d[6] - d[4])) < 1e-10) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

    }
}