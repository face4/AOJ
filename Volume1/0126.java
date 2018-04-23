
/**
 * 0126 Puzzle
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            int[][] map = new int[9][9];
            boolean[][] ok = new boolean[9][9];
            for (int j = 0; j < 9; j++) {
                String[] input = br.readLine().split(" ");
                for (int k = 0; k < 9; k++) {
                    map[j][k] = Integer.parseInt(input[k]);
                }
            }

            // horizontal check
            for (int j = 0; j < 9; j++) {
                boolean[] oneToNine = new boolean[10]; // index0は使わない
                for (int k = 0; k < 9; k++) {
                    if (!oneToNine[map[j][k]]) {
                        oneToNine[map[j][k]] = true;
                    } else {
                        ok[j][k] = true;
                        for (int l = 0; l < k; l++) {
                            if (map[j][l] == map[j][k]) {
                                ok[j][l] = true;
                            }
                        }
                    }
                }
            }

            // vertical check
            for (int j = 0; j < 9; j++) {
                boolean[] oneToNine = new boolean[10];
                for (int k = 0; k < 9; k++) {
                    if (!oneToNine[map[k][j]]) {
                        oneToNine[map[k][j]] = true;
                    } else {
                        ok[k][j] = true;
                        for (int l = 0; l < k; l++) {
                            if (map[l][j] == map[k][j]) {
                                ok[l][j] = true;
                            }
                        }
                    }
                }
            }

            // square check

            
            // display
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 9; k++) {
                    if (ok[j][k])
                        System.out.print("*");
                    else
                        System.out.print(" ");

                    System.out.print(map[j][k]);
                }
                System.out.println();
            }

        }
    }
}