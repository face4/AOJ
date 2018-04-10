// depth first search
/**
 * 0030 Sum of Integers
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int answer = 0;

    static void initialize() {
        answer = 0;
    }

    static void dfs(int restn, int restSum, int now) {
        if (restSum == 0 && restn == 0) {
            answer++;
            return;
        }

        if (now == 10 || restn == 0) {
            return;
        }

        dfs(restn - 1, restSum - now, now + 1); // nowを採用
        dfs(restn, restSum, now + 1); // nowを不採用
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (!(line = br.readLine()).equals("0 0")) {
            String[] input = line.split(" ");
            int n = Integer.parseInt(input[0]);
            int s = Integer.parseInt(input[1]);

            initialize();
            dfs(n, s, 0);

            System.out.println(answer);
        }
    }
}