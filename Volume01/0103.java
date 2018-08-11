
/**
 * 0103 BaseBall Simulation
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            int out = 0;
            boolean[] rui = new boolean[3];
            int score = 0;

            while (out != 3) {
                String event = br.readLine();
                if (event.equals("HIT")) {
                    if (rui[2])
                        score++;
                    for (int ii = 2; ii > 0; ii--) {
                        rui[ii] = rui[ii - 1];
                    }
                    rui[0] = true;
                } else if (event.equals("HOMERUN")) {
                    score += 1;
                    for (boolean b : rui) {
                        if (b)
                            score++;
                    }
                    rui = new boolean[3];
                } else if (event.equals("OUT")) {
                    out++;
                }
            }

            System.out.println(score);
        }
    }
}