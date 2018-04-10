// いまいちよくわかってない
/**
 * 0076 Treasure Hunt II
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while(!(line = br.readLine()).equals("-1")){
            int n = Integer.parseInt(line);
            double x = 1.0;
            double y = 0.0;
            double deg = 180;

            for(int i = 1; i < n; i++){
                deg -= 90;
                x += Math.cos(deg / 180.0 * Math.PI);
                y += Math.sin(deg / 180.0 * Math.PI);
                deg = Math.atan(y/x) * 180.0 / Math.PI;
                if(x <= 0 && y >= 0) deg += 180.0;
                if(x <= 0 && y <= 0) deg += 180.0;
                // System.out.println(x + ":" + y + ":" + deg);
            }

            System.out.printf("%.2f%n", y);
            System.out.printf("%.2f%n", x);
        }
    }
}