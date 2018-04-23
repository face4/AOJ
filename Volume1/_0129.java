// この実装は明らかに間違っています.

/**
 * 0129 Hide-and-Seek Supporting System 
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        String[] input;

        while (!((line = br.readLine()).equals("0"))) {
            int n = Integer.parseInt(line);
            int[][] wall = new int[3][n];
            for (int i = 0; i < n; i++) {
                input = br.readLine().split(" ");
                wall[0][i] = Integer.parseInt(input[0]);
                wall[1][i] = Integer.parseInt(input[1]);
                wall[2][i] = Integer.parseInt(input[2]);
            }

            int m = Integer.parseInt(br.readLine());
            int tx, ty, sx, sy, a, b, c;
            double d;

            x: for (int i = 0; i < m; i++) {
                input = br.readLine().split(" ");
                tx = Integer.parseInt(input[0]);
                ty = Integer.parseInt(input[0]);
                sx = Integer.parseInt(input[0]);
                sy = Integer.parseInt(input[0]);

                a = (sy - ty);
                b = (tx - sx);
                c = -tx*(sy - ty) - ty*(tx - sx);

                for (int j = 0; j < n; j++) {
                    if ((Math.abs(a * wall[j][0] + b * wall[j][1] + c) / Math.sqrt(a * a + b * b)) > wall[j][2]) {
                        System.out.println("Danger");
                        continue x;
                    }
                }

                System.out.println("Safe");
            }

        }
    }
}