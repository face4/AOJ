
/**
 * 0055 Sequence
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;
        while ((line = br.readLine()) != null) {
            double sum = 0;
            double[] arr = new double[10];
            arr[0] = Double.parseDouble(line);
            sum += arr[0];
            for (int i = 1; i < 10; i++) {
                if (i % 2 == 0) {
                    arr[i] = arr[i - 1] / 3;
                } else {
                    arr[i] = arr[i - 1] * 2;
                }
                sum += arr[i];
            }
            System.out.printf("%.8f%n", sum);
        }
    }
}