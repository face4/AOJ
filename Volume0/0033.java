// Wrong Answer!!
/**
 * 0033 Ball
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] origin = new int[10];
        int[] s = new int[11];
        int[] t = new int[11];

        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            int posS = 0;
            int posT = 0;

            s[0] = -1;
            t[0] = -1;

            for (int j = 1; j < 11; j++) {
                s[j] = 0;
                t[j] = 0;
            }

            String[] line = br.readLine().split(" ");
            boolean result = true;

            for (int j = 0; j < 10; j++) {
                origin[j] = Integer.parseInt(line[j]);
            }

            for (int j = 0; j < 10; j++) {
                if (origin[j] > s[posS]) {
                    // sで受け入れ可
                    if (origin[j] > t[posT]) {
                        // sでもtでも受け入れ可
                        if (s[posS] < t[posT]) {
                            posT++;
                            t[posT] = origin[j];
                        } else {
                            posS++;
                            s[posS] = origin[j];
                        }
                    } else {
                        // sのみで受け入れ可
                        posS++;
                        s[posS] = origin[j];
                    }
                } else if (origin[j] > t[posT]) {
                    // tのみで受け入れ可
                    posT++;
                    t[posT] = origin[j];
                } else {
                    // sでもtでも受け入れ不可
                    result = false;
                    break;
                }

            }

            if (result) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }

        } // end of for

    }
}