/**
 * 0005-GCD and LCM
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while( (line = br.readLine()) != null){
            String[] input = line.split(" ");

            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);

            int x = getGCD(Math.max(a,b) , Math.min(a,b));
            long y = (long)a*(long)b/x;

            System.out.println(x + " " + y);
        }
    }

    static int getGCD(int b , int s){
        return (b%s == 0) ? s : getGCD(s , b%s);
    }

}