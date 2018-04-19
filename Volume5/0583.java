/**
 * 0583-Common Divisors
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class Main0583{

    static int gcd(int a , int b){
        return b == 0 ? a : gcd(b , a%b);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int num = Integer.valueOf(br.readLine());
        String[] inputs = br.readLine().split(" ");
        int[] input = new int[num];

        for(int i = 0; i < num; i++)    input[i] = Integer.valueOf(inputs[i]);
        
        int GCD = gcd(Math.max(input[0] , input[1]) , Math.min(input[0] , input[1]));
        
        if(num == 3) GCD = gcd(Math.max(GCD, input[2]) , Math.min(GCD , input[2]));

        for(int i = 1; i <= GCD; i++){
            if((GCD % i) == 0) System.out.println(i);
        }
        
    }
}