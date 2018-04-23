
/**
 * 0108 Operation of Frequency of Appearance
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (!(line = br.readLine()).equals("0")) {
            int n = Integer.parseInt(line);
            int[] before = new int[n];
            int[] after = new int[n];
            String[] input = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                before[i] = Integer.parseInt(input[i]);
            }

            int phase = 0;
            while (true) {
                for (int i = 0; i < n; i++) {
                    int now = before[i];
                    int count = 0;
                    for (int j = 0; j < n; j++) {
                        if (now == before[j])
                            count++;
                    }
                    after[i] = count;
                }

                if (Arrays.equals(before, after)) {
                    break;
                } else {
                    before = after.clone();
                }

                phase++;
            }

            System.out.println(phase);
            for (int i = 0; i < n; i++) {
                if (i == 0)
                    System.out.print(after[i]);
                else
                    System.out.print(" " + after[i]);
            }
            System.out.println();
        }
    }
}