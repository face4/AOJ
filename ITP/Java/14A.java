/**
 * ITP1_4_A A/B Problem
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" " , 2);
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);

        double ad = (double)a;
        double bd = (double)b;

        System.out.print(a/b + " " + a%b + " ");
        System.out.printf("%.5f\n" , ad/bd);
    }
}