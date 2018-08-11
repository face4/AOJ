
/**
 * 0118 Property Distribution
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int H;
    static int W;

    static boolean[][] done;
    static char[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (!(line = br.readLine()).equals("0 0")) {
            String[] input = line.split(" ");
            H = Integer.parseInt(input[0]);
            W = Integer.parseInt(input[1]);
            done = new boolean[H][W];
            map = new char[H][W];
            int res = 0;

            for (int i = 0; i < H; i++) {
                map[i] = br.readLine().toCharArray();
            }

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (done[i][j]) {
                        continue;
                    } else {
                        res++;
                        // System.out.println(map[i][j] + "を分配します...");
                        dist(i, j, map[i][j]);
                    }
                }
            }

            System.out.println(res);
        }
    }

    static void dist(int h, int w, char c) {
        try {
            char x = map[h][w];
            if (!done[h][w] && x == c) {
                done[h][w] = true; // 分配済みフラグを立てる
                dist(h, w - 1, c);
                dist(h, w + 1, c);
                dist(h - 1, w, c);
                dist(h + 1, w, c);
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            return;
        }
    }
}