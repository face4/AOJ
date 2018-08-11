
/**
 * 0026 Dropping Ink
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int[][] paper = new int[10][10];

    static void drop(int x, int y) {
        try {
            paper[y][x]++;
        } catch (ArrayIndexOutOfBoundsException e) {
            return;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input;

        // initialize
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                paper[i][j] = 0;
            }
        }

        while ((input = br.readLine()) != null) {
            String[] info = input.split(",");
            int x = Integer.parseInt(info[0]);
            int y = Integer.parseInt(info[1]);

            drop(y, x);
            drop(y + 1, x);
            drop(y - 1, x);
            drop(y, x + 1);
            drop(y, x - 1);

            int size = Integer.parseInt(info[2]);

            if (size >= 2) {
                drop(y + 1, x + 1);
                drop(y + 1, x - 1);
                drop(y - 1, x + 1);
                drop(y - 1, x - 1);
            }
            if (size >= 3) {
                drop(y + 2, x);
                drop(y - 2, x);
                drop(y, x + 2);
                drop(y, x - 2);
            }

        }

        int clear = 0;
        int max = 0;

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(paper[i][j] == 0){
                    clear++;
                }

                if(paper[i][j] > max){
                    max = paper[i][j];
                }
            }
        }

        System.out.println(clear);
        System.out.println(max);
    }
}