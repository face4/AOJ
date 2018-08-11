
/**
 * 0057 The Number of Area
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;
        int[] arr = new int[10001];
        arr[1] = 2;

        for (int i = 2; i <= 10000; i++) {
            arr[i] = arr[i - 1] + i;
        }

        while ((line = br.readLine()) != null) {
            int n = Integer.parseInt(line);
            System.out.println(arr[n]);
        }
    }
}