import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int a = Integer.valueOf(input[0]);
        int b = Integer.parseInt(input[1]);

        System.out.println(gcd(a,b));

    }

    private static int gcd(int a , int b){
        int result = 1;

        if(b > a){
            int tmp = b;
            b = a;
            a = tmp;
        }

        if((a % b) == 0) return b;
        else return gcd(b , a%b);
        
    }
}