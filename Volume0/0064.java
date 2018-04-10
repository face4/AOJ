
/**
 * 0064 Secret Number
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int answer = 0;
        String line;
        while ((line = br.readLine()) != null) {
            char[] arr = line.toCharArray();
            boolean isConstruct = false;

            String s = "";
            for (int i = 0; i < arr.length; i++) {
                if ('0' <= arr[i] && arr[i] <= '9') {
                    if (isConstruct) {
                        s = s + arr[i];
                    } else {
                        s = String.valueOf(arr[i]);
                        isConstruct = true;
                    }
                } else {
                    if (isConstruct) {
                        answer += Integer.parseInt(s);
                        s = "";
                        isConstruct = false;
                    }
                }
            }

            if (isConstruct) {
                answer += Integer.parseInt(s);
            }

        }

        System.out.println(answer);
    }
}