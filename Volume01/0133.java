
/**
 * 0133 Rotation of a Pattern
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[][] map = new char[8][8];

        for (int i = 0; i < 8; i++) {
            map[i] = br.readLine().toCharArray();
        }

        // 90
        System.out.println("90");
        for (int i = 0; i < 8; i++) {
            for (int j = 7; j >= 0; j--) {
                System.out.print(map[j][i]);
            }
            System.out.println();
        }

        System.out.println("180");
        for (int i = 7; i >= 0; i--) {
            for (int j = 7; j >= 0; j--) {
                System.out.print(map[i][j]);
            }
            System.out.println();
        }

        System.out.println("270");
        for (int i = 7; i >= 0; i--) {
            for (int j = 0; j < 8; j++) {
                System.out.print(map[j][i]);
            }
            System.out.println();
        }

    }
}