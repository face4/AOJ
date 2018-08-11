
/**
 * 0130 Train
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            String res = line.substring(0, 1);
            line = line.substring(1);
            int index = 0;
            for (;;) {
                if (line.length() == 0)
                    break;

                if (line.substring(0, 2).equals("<-")) {
                    index--;
                } else if (line.substring(0, 2).equals("->")) {
                    index++;
                }
                line = line.substring(2);
                String next = line.substring(0, 1);
                line = line.substring(1);

                if (index < 0) {
                    res = next + res;
                    index = 0;
                } else if (index >= res.length()) {
                    res = res + next;
                } else {
                    // do nothing.
                }
            }

            System.out.println(res);
        }
    }
}