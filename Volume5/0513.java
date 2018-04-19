
/**
 * 0513 Shuffle The Cards
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int n;
    static int[] cards;
    static int[] clone;

    static void riffle() {
        clone = cards.clone();
        for (int i = 0; i < n; i++) {
            cards[2 * i] = clone[i];
            cards[2 * i + 1] = clone[n + i];
        }
    }

    static void cut(int k) {
        clone = cards.clone();
        for (int i = 0; i < 2 * n - k; i++) {
            cards[i] = clone[i + k];
        }
        for (int i = 0; i < k; i++) {
            cards[2 * n - k + i] = clone[i];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        cards = new int[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            cards[i] = i + 1;
        }

        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            int k = Integer.parseInt(br.readLine());
            if (k == 0) {
                riffle();
            } else {
                cut(k);
            }
        }

        for (int a : cards) {
            System.out.println(a);
        }

    }
}