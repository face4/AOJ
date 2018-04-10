// MLE を解決できません
/**
 * 0040 Affine Cipher
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            char[] line = br.readLine().toCharArray();
            for(int j = 0; j < line.length; j++){
                line[j] -= 'a';
            }

            int alpha = 1;
            String result = "";

            decrypt: while (true) {
                for (int beta = 1; beta <= 25; beta++) {
                    for (int j = 0; j < line.length; j++) {
                        if (0 <= line[j] && line[j] < 26) {
                            result += (char) ((alpha * line[j] + beta) % 26 + 'a');
                        } else {
                            result += (char)(line[j] + 'a');
                        }
                    }
                    if (result.contains("this") || result.contains("that")) {
                        break decrypt;
                    }
                    result = "";
                }

                alpha += ((alpha + 2) % 13 == 0) ? 4 : 2;
            }

            System.out.println(result);
            result = "";
        }

    }
}