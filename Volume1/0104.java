
/**
 * 0104 Magical Tiles
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (!(line = br.readLine()).equals("0 0")) {
            String[] input = line.split(" ");
            int H = Integer.parseInt(input[0]);
            int W = Integer.parseInt(input[1]);
            char[][] tiles = new char[H][W];
            boolean[][] b = new boolean[H][W];

            for (int i = 0; i < H; i++) {
                tiles[i] = br.readLine().toCharArray();
            }

            int posX = 0;
            int posY = 0;
            String result = "LOOP";

            while (!b[posY][posX]) {
                b[posY][posX] = true;
                if (tiles[posY][posX] == '.') {
                    result = posX + " " + posY;
                    break;
                } else if (tiles[posY][posX] == 'v') {
                    posY++;
                } else if (tiles[posY][posX] == '<') {
                    posX--;
                } else if (tiles[posY][posX] == '>') {
                    posX++;
                } else if (tiles[posY][posX] == '^') {
                    posY--;
                }
            }

            System.out.println(result);
        }
    }
}