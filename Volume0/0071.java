
/**
 * 0071 Bombs Chain
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int[][] map = new int[8][8];

    static void explosion(int i, int j) {
        if (i < 0 || i > 7 || j < 0 || j > 7)
            return;
        if (map[i][j] == 1) {
            map[i][j] = 0;
            for (int x = 1; x <= 3; x++) {
                explosion(i + x, j);
                explosion(i - x, j);
                explosion(i, j + x);
                explosion(i, j - x);
            }
        } else {
            return;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String line;
        br.readLine();

        for (int num = 0; num < n; num++) {
            // initialize map
            for (int i = 0; i < 8; i++) {
                line = br.readLine();
                char[] c = line.toCharArray();
                for (int j = 0; j < 8; j++) {
                    if (c[j] == '1') {
                        map[i][j] = 1;
                    } else {
                        map[i][j] = 0;
                    }
                }
            }

            int x = Integer.parseInt(br.readLine());
            int y = Integer.parseInt(br.readLine());

            explosion(y - 1, x - 1);

            System.out.println("Data " + (num + 1) + ":");
            for (int i = 0; i < 8; i++) {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < 8; j++) {
                    sb.append(map[i][j]);
                }
                System.out.println(sb);
            }

            br.readLine();
        }

    }
}