
/**
 * 0136 Frequency Distribution of Height
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] data = new int[6];
        Arrays.fill(data, 0);

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            double height = Double.parseDouble(br.readLine());
            if (height < 165)
                data[0]++;
            else if (height < 170)
                data[1]++;
            else if (height < 175)
                data[2]++;
            else if (height < 180)
                data[3]++;
            else if (height < 185)
                data[4]++;
            else
                data[5]++;
        }

        for (int i = 0; i < 6; i++) {
            System.out.print((i + 1) + ":");
            for (int j = 0; j < data[i]; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}