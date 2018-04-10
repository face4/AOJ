
/**
 * 0067 The Number of Island
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int[][] map = new int[12][12];

    static void removeIslands(int i, int j){
        if(i < 0 || i > 11 || j < 0 || j > 11) return;
        if(map[i][j] == 1){
            map[i][j] = 0;
            removeIslands(i-1,j);
            removeIslands(i+1,j);
            removeIslands(i,j+1);
            removeIslands(i,j-1);
        }else{
            return;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            // initialize map
            for (int i = 0; i < 12; i++) {
                char[] c = line.toCharArray();
                for (int j = 0; j < 12; j++) {
                    if (c[j] == '1') {
                        map[i][j] = 1;
                    } else {
                        map[i][j] = 0;
                    }
                }
                line = br.readLine();
            }

            int answer = 0;
            // counting islands
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 12; j++) {
                    if (map[i][j] == 1) {
                        answer++;
                        removeIslands(i, j);
                    }
                }
            }

            System.out.println(answer);

        }
    }
}