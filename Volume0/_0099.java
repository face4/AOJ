// TLE.　前回のイベントの結果を利用して今回のイベントの結果を求める必要がある.

/**
 * 0099 Surf Smelt Fishing Contest II 
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int q = Integer.parseInt(input[1]);

        int[] scores = new int[n + 1]; // default 0
        HashSet<Integer> par = new HashSet<Integer>();

        for (int i = 0; i < q; i++) {
            String[] line = br.readLine().split(" ");
            scores[Integer.parseInt(line[0])] += Integer.parseInt(line[1]);
            par.add(Integer.parseInt(line[0]));

            int person = -1;
            int maxValue = Integer.MIN_VALUE;
            Object[] x = par.toArray();
            int[] y = new int[x.length];
            for (int j = 0; j < x.length; j++) {
                y[j] = (int) x[j];
            }

            Arrays.sort(y);

            for (int j : y) {
                if (scores[j] > maxValue) {
                    person = j;
                    maxValue = scores[j];
                }
            }

            System.out.println(person + " " + maxValue);
        }

    }
}