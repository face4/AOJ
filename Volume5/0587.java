
/**
 * 0587 Tunnel
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        int max = m;
        int now = m;

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            int diff = Integer.parseInt(line[0]) - Integer.parseInt(line[1]);

            if (now + diff < 0) {
                max = 0;
                break;
            }

            now += diff;

            max = Math.max(max,now);
        }

        System.out.println(max);

    }
}