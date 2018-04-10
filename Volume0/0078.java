
/**
 * 0078 Magic Square
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int[][] getMagicSquare(int n) {
        int[][] result = new int[n][n];
        int x = n / 2;
        int y = n / 2 + 1;
        result[y][x] = 1;

        for (int i = 1; i < n * n; i++) {
            x++;
            y++;
            // x,yを決める
            while (true) {
                if (x == -1)
                    x = n - 1; // 左
                if (x == n)
                    x = 0; // 右
                if (y == n)
                    y = 0; // 下 

                if (result[y][x] == 0) {
                    break;
                } else {
                    x--;
                    y++;
                }
            }

            result[y][x] = i + 1;
        }

        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;

        while (!(line = br.readLine()).equals("0")) {
            int n = Integer.parseInt(line);

            int[][] answer = getMagicSquare(n);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(String.format("%4d", answer[i][j]));
                }
                System.out.println();
            }
        }

    }
}