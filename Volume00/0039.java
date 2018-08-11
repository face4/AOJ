/**
 * 0039 Roman Figure
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {

    static int getValue(char c) {
        switch (c) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return -1; // unreachable
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;
        
        while ((line = br.readLine()) != null) {
            int result = 0;
            int before = Integer.MAX_VALUE;
            int next;

                for (int i = 0; i < line.length(); i++) {
                    next = getValue(line.charAt(i));

                    if (before >= next)
                        result += next;
                    else
                        result = result - before + (next - before);

                    before = next;
                }
                System.out.println(result);
        }

    }
}