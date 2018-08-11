// なぜかWA
/**
 * 0088 The Code A Doctor Loved
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static String decrypt(String x) {
        int dec = Integer.parseInt(x, 2);
        if (dec <= 25) {
            return String.valueOf((char) ('A' + dec));
        } else if (dec == 26) {
            return " ";
        } else if (dec == 27) {
            return ".";
        } else if (dec == 28) {
            return ",";
        } else if (dec == 29) {
            return "-";
        } else if (dec == 30) {
            return "\'";
        } else if (dec == 31) {
            return "?";
        }

        return "*****"; // unreachable
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = { " ", "\'", ",", "-", ".", "?", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
        String[] f = { "101", "000000", "000011", "10010001", "010001", "000001", "100101", "10011010", "0101", "0001",
                "110", "01001", "10011011", "010000", "0111", "10011000", "0110", "00100", "10011001", "10011110",
                "00101", "111", "10011111", "1000", "00110", "00111", "10011100", "10011101", "000010", "10010010",
                "10010011", "10010000" };

        String line;
        while ((line = br.readLine()) != null) {
            StringBuilder sb = new StringBuilder();
            for (char c : line.toCharArray()) {
                for (int i = 0; i < s.length; i++) {
                    if (s[i].equals(String.valueOf(c))) {
                        sb.append(f[i]);
                        break;
                    }
                }
            }
            for (int i = 0; i < sb.length()%5; i++) {
                sb.append("0");
            }

            StringBuilder result = new StringBuilder();

            while (sb.length() > 5) {
                String x = sb.substring(0, 5);
                sb.delete(0, 5);
                result.append(decrypt(x));
            }

            result.append(decrypt(sb.toString()));

            System.out.println(result);
        }
    }
}