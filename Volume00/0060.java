
/**
 * 0060 Card Game
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            String[] input = line.split(" ");
            int c1 = Integer.parseInt(input[0]);
            int c2 = Integer.parseInt(input[1]);
            int c3 = Integer.parseInt(input[2]);

            boolean[] cards = new boolean[11];
            cards[c1] = true;
            cards[c2] = true;
            cards[c3] = true;

            int available = 0;
            for (int i = 1; i <= 10; i++) {
                if (!cards[i] && c1 + c2 + i <= 20) {
                    available++;
                }
            }

            if (available > 3) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

    }
}