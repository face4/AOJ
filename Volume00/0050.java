
/**
 * 0050 Apple and Peach
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = br.readLine();
        char[] arr = line.toCharArray();

        // 以下でもACだが、元文字列にpea-chが含まれている場合は正しく機能しない
        /*
        line = line.replaceAll("apple", "pea-ch");
        line = line.replaceAll("peach", "apple");
        line = line.replaceAll("pea-ch", "peach");
        */

        for (int i = 0; i < arr.length - 4; i++) {
            if (line.substring(i, i + 5).equals("apple")) {
                arr[i] = 'p';
                arr[i+1] = 'e';
                arr[i+2] = 'a';
                arr[i+3] = 'c';
                arr[i+4] = 'h';
                i += 4;
            }else if(line.substring(i, i + 5).equals("peach")) {
                arr[i] = 'a';
                arr[i+1] = 'p';
                arr[i+2] = 'p';
                arr[i+3] = 'l';
                arr[i+4] = 'e';
                i += 4;
            }
        }
        System.out.println(arr);
    }
}