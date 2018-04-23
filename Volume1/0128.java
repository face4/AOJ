
/**
 * 0128 Abacus
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        boolean flag = false;
        char[][] res = new char[8][5];

        while ((line = br.readLine()) != null) {
            if (flag) {
                System.out.println();
            }

            line = String.format("%5s", line).replaceAll(" ", "0");
            for (int i = 0; i < 5; i++) {
                int n = (int) (line.charAt(i) - '0');
                char[] x = dec(n).toCharArray();
                for (int j = 0; j < 8; j++) {
                    res[j][i] = x[j];
                }
            }

            // display
            for (char[] a : res) {
                for (char c : a) {
                    System.out.print(c);
                }
                System.out.println();
            }

            flag = true;
        }
    }

    static String dec(int n) {
        switch (n) {
        case 0:
            return "* = ****";
        case 1:
            return "* =* ***";
        case 2:
            return "* =** **";
        case 3:
            return "* =*** *";
        case 4:
            return "* =**** ";
        case 5:
            return " *= ****";
        case 6:
            return " *=* ***";
        case 7:
            return " *=** **";
        case 8:
            return " *=*** *";
        case 9:
            return " *=**** ";
        }

        return null; // unreachable
    }
}