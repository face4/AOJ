
/**
 * ALDS1_10_A Fibonacci Number
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {

    // メモ化(TLE)
    static int fibm(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;

        return fibm(n - 1) + fibm(n - 2);
    }

    // 動的計画法
    static boolean[] done;
    static int[] memo;

    static int fib(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;

        if (done[n]) {
            return memo[n];
        } else {
            int res = fib(n - 1) + fib(n - 2);
            done[n] = true;
            memo[n] = res;
            return res;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        done = new boolean[n + 1];
        memo = new int[n + 1];
        System.out.println(fib(n));
    }
}