// dynamic programming
// 価値の最大値は出せるけど、その時の重さを出せない
/**
 * 0042 A Thief
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static boolean[][] done;
    static int[][] memo;

    static int U;
    static int N;

    static int[] V;
    static int[] W;
    
    static int lastU;

    static int search(int i , int u){
        if(i == N){
            lastU = Math.max(lastU, u); // lastUは間違っています.
            return 0;
        }

        if(done[i][u]){
            return memo[i][u];
        }else{
            int res;
            if(u < W[i]){
                res = search(i+1,u);
            }else{
                res = Math.max(search(i+1,u), search(i+1, u-W[i]) + V[i]);
            }
            done[i][u] = true;
            memo[i][u] = res;
            return res;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        int caseNum = 1;

        while (!(line = br.readLine()).equals("0")) {
            U = Integer.parseInt(line);
            N = Integer.parseInt(br.readLine());
            V = new int[N];
            W = new int[N];

            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(",");
                V[i] = Integer.parseInt(input[0]);
                W[i] = Integer.parseInt(input[1]);
            }

            // メモ化
            done = new boolean[N][U + 1];
            memo = new int[N][U + 1];

            // これいる？
            lastU = Integer.MIN_VALUE;

            int result = search(0,U);
            System.out.println("case : " + caseNum++);
            System.out.println(result);
            System.out.println(lastU);
        }
    }
}