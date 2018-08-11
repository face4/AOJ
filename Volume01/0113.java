/**
 * 0113 Period
 */

// 過去イチで酷い実装、いつかリファクタリングしたい
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            String[] input = line.split(" ");
            int p = Integer.parseInt(input[0]);
            int q = Integer.parseInt(input[1]);
            String qs = ""; // 商の羅列
            int[] rs = new int[81]; // 余りの羅列
            int pos = 0;
            StringBuilder second = new StringBuilder(); // 循環部を表示するため
            boolean isLoop = false;

            p -= (p / q) * q; // p < qにする
            rs[pos] = p;

            wh: while (true) {
                int sho = (10 * p) / q;
                p = (10 * p) % q;

                if (p == 0) {
                    qs = qs + sho;
                    break;
                }

                int i;
                for (i = pos; i >= 0; i--) {
                    if (rs[i] == p) {
                        qs = qs + sho;

                        int marklength = qs.length() - i;
                        for (int j = 0; j < i; j++) {
                            second.append(" ");
                        }
                        for (int j = 0; j < marklength; j++) {
                            second.append("^");
                        }
                        isLoop = true;
                        break wh;
                    }
                }

                qs = qs + sho;
                rs[++pos] = p;
            }

            if (isLoop) {
                System.out.println(qs);
                System.out.println(second.toString());
            } else {
                System.out.println(qs);
            }

        }
    }
}