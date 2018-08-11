
/**
 * 0082 Flying Jenny
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] merry = { 4, 1, 4, 1, 2, 1, 2, 1 };

        String line;
        String[] input;
        int[] customer = new int[8];

        while ((line = br.readLine()) != null) {
            input = line.split(" ");
            for (int i = 0; i < 8; i++) {
                customer[i] = Integer.parseInt(input[i]);
            }

            int answer = -1; // index
            int V = 0;
            int min = Integer.MAX_VALUE;
            int tens;

            for (int i = 0; i < 8; i++) {
                tens = 10000000;
                int score = 0;
                int tmpv = 0;
                for (int j = 0; j < 8; j++) {
                    score += Math.max(0, merry[(i + j) % 8] - customer[j]);
                    tmpv += tens * merry[(i + j) % 8];
                    tens /= 10;
                }
                if (min == score && tmpv < V) {
                    answer = i;
                    V = tmpv;
                    min = score; // do nothing. ritual
                } else if (score < min) {
                    answer = i;
                    V = tmpv;
                    min = score;
                }
            }

            for (int i = 0; i < 8; i++) {
                if (i == 0)
                    System.out.print(merry[answer]);
                else
                    System.out.print(" " + merry[(answer + i) % 8]);
            }
            System.out.println();
        }
    }
}