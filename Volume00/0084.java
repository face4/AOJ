
/**
 * 0084 Search Engine
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringBuilder sb = new StringBuilder();
        StringBuilder re = new StringBuilder();
        int index = 0;
        while (index < line.length()) {
            char c = line.charAt(index);
            if (c == ' ' || c == '.' || c == ',') {
                if (3 <= sb.length() && sb.length() <= 6) {
                    re.append(sb.toString() + " ");
                }
                sb.setLength(0);
            } else {
                sb.append(c);
            }
            index++;
        }
        if (sb.length() != 0) {
            if (3 <= sb.length() && sb.length() <= 6) {
                re.append(sb.toString() + " ");
            }
        }
        System.out.println(re.toString().trim());
    }
}