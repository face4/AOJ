/**
 * ITP1_4_B Circle
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        double r = Double.parseDouble(br.readLine());
        double L = 2.0 * r * Math.PI;
        double S = r * r * Math.PI;
        
        System.out.printf("%.6f " , S);
        System.out.printf("%.6f\n" , L);
    }
}