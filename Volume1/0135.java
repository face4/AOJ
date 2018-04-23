
/**
 * 0135 Clock Short Hand and Long Hand
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(":");
            int hour = Integer.parseInt(input[0]);
            int min = Integer.parseInt(input[1]);
            double lhand = (hour * 60 + min) / 2.0;
            double shand = (min * 6.0);
            double deg = Math.abs(lhand - shand);
            if ((0 <= deg && deg < 30) || (330 < deg && deg <= 360)) {
                System.out.println("alert");
            } else if ((90 <= deg && deg <= 180) || (180 <= deg && deg <= 270)) {
                System.out.println("safe");
            } else {
                System.out.println("warning");
            }
        }
    }
}