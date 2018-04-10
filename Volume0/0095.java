
/**
 * 0095 Surf Smelt Fishing Contest
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] score = new int[n + 1];

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            score[Integer.parseInt(input[0])] = Integer.parseInt(input[1]);
        }

        int maxValue = Integer.MIN_VALUE;
        int maxIndex = -1;
        for (int i = 1; i <= n; i++) {
            if (maxValue < score[i]) {
                maxValue = score[i];
                maxIndex = i;
            }
        }

        System.out.println(maxIndex + " " + maxValue);
    }
}