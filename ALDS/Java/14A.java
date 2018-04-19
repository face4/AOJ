/**
 * ALDS 1_4_A Linear Search
 */

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main {

    static int linearSearch(int[] a, int x) {
        int pos = 0;
        a[a.length - 1] = x;
        while (a[pos] != x) {
            pos++;
        }
        return pos;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int result = 0;

        int n = Integer.parseInt(br.readLine());
        int[] S = new int[n + 1];
        String[] inputs = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            S[i] = Integer.parseInt(inputs[i]);
        }

        int q = Integer.parseInt(br.readLine());
        String[] inputt = br.readLine().split(" ");
        for (String str : inputt) {
            if (linearSearch(S, Integer.parseInt(str)) != n) {
                result++;
            }
        }

        System.out.println(result);
    }
}