
/**
 * 0137 Middle-Square Method
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            System.out.println("Case " + (i + 1) + ":");
            int x = Integer.parseInt(br.readLine());
            for (int j = 0; j < 10; j++) {
                String s = String.format("%8s", String.valueOf(x * x)).replaceAll(" ", "0");
                x = Integer.parseInt(s.substring(2, 6));
                System.out.println(x);
            }
        }
    }
}