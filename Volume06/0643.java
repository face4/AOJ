
/**
 * 0643 Trunk Road
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] size = br.readLine().split(" ");
        int H = Integer.parseInt(size[0]);
        int W = Integer.parseInt(size[1]);

        int[][] map = new int[H][W];

        // data in
        for (int h = 0; h < H; h++) {
            String[] line = br.readLine().split(" ");
            for (int w = 0; w < W; w++) {
                map[h][w] = Integer.parseInt(line[w]);
            }
        }

        int answer = Integer.MAX_VALUE;

        // select road
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                int score = 0;
                // calculate distance
                for (int hh = 0; hh < H; hh++) {
                    for (int ww = 0; ww < W; ww++) {
                        score += map[hh][ww] * Math.min(Math.abs(h - hh), Math.abs(w - ww));
                    }
                }
                answer = Math.min(answer, score);
            }
        }

        System.out.println(answer);
    }
}