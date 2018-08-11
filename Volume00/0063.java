
/**
 * 0063 Palindrome
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static boolean isPalindrome(String s) {
        for (int i = 0; i <= (s.length() - 1)/ 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;
        int result = 0;
        while ((line = br.readLine()) != null) {
            if (isPalindrome(line))
                result++;
        }
        System.out.println(result);
    }
}