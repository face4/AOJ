
/**
 * 0127 Pocket Pager Input
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        char[][] map = { { 'a', 'f', 'k', 'p', 'u', 'z' }, { 'b', 'g', 'l', 'q', 'v', '.' },
                { 'c', 'h', 'm', 'r', 'w', '?' }, { 'd', 'i', 'n', 's', 'x', '!' }, { 'e', 'j', 'o', 't', 'y', ' ' } };
        while ((line = br.readLine()) != null) {

            if (line.length() % 2 == 1) {
                System.out.println("NA");
                continue;
            }

            String result = "";
            while (line.length() > 1) {
                int w = (int) (line.charAt(0) - '0');
                int h = (int) (line.charAt(1) - '0');
                try {
                    result += map[h - 1][w - 1];
                } catch (ArrayIndexOutOfBoundsException e) {
                    result = "NA";
                    break;
                }
                line = line.substring(2);
            }

            System.out.println(result);
        }
    }
}