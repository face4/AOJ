/**
 * ITP1_10_B Triangle
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] input = br.readLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        int C = Integer.parseInt(input[2]);

        double S = a * b * Math.sin(Math.toRadians(C)) /2;
        double L = a + b + Math.sqrt(a*a + b*b -2*a*b*Math.cos(Math.toRadians(C)));
        double h = 2 * S / a;

        System.out.println(S);
        System.out.println(L);
        System.out.println(h);
    }
}