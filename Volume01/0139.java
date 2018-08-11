
/**
 * 0139 Snakes
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String res = "NA";
            String sna = br.readLine();

            if (sna.length() < 6) {
                System.out.println(res);
                continue;
            }

            if (sna.startsWith(">\'")) {
                sna = sna.substring(2);
                if (sna.startsWith("=")) {
                    int eq1 = 0;
                    for (char c : sna.toCharArray()) {
                        if (c == '=')
                            eq1++;
                        else
                            break;
                    }
                    sna = sna.substring(eq1);
                    if (sna.startsWith("#")) {
                        sna = sna.substring(1);
                        int eq2 = 0;
                        for (char c : sna.toCharArray()) {
                            if (c == '=')
                                eq2++;
                            else
                                break;
                        }

                        if (eq1 == eq2) {
                            sna = sna.substring(eq2);
                            if (sna.equals("~")) {
                                res = "A";
                            }
                        }
                    }
                }
            } else if (sna.startsWith(">^")) {
                sna = sna.substring(2);
                int q = 0;
                while (sna.startsWith("Q=")) {
                    sna = sna.substring(2);
                    q++;
                }
                if (q > 0) {
                    if (sna.equals("~~")) {
                        res = "B";
                    }
                }
            }

            System.out.println(res);
        }
    }
}