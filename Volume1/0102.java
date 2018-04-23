
/**
 * 0102-Matrix-like Computation
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int size;

        while ((size = Integer.parseInt(br.readLine())) != 0) {
            int[][] table = new int[size + 1][size + 1];

            for (int i = 0; i < size; i++) {
                String[] horizontal = br.readLine().split(" ");
                for (int j = 0; j < size; j++) {
                    table[i][j] = Integer.parseInt(horizontal[j]);
                }
            }

            deploySum(table);

            for (int i = 0; i <= size; i++) {
                for (int j = 0; j < size; j++) {
                    System.out.print(String.format("%5s", table[i][j]));
                }
                System.out.println(String.format("%5s", table[i][size]));
            }

        }
    }

    public static void deploySum(int[][] data) {
        int size = data.length;

        //left-right
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1; j++) {
                data[i][size - 1] += data[i][j];
            }
        }

        //up-down
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1; j++) {
                data[size - 1][i] += data[j][i];
            }
        }

    }

}