/**
 * 0014-Integral
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;

        while( (line = br.readLine()) != null){
            int a = Integer.parseInt(line);
            int sum = 0;
            int time = 1;

            while(a*time < 600){
                sum += a * (int)(Math.pow(a*time , 2));
                time++;
            }

            System.out.println(sum);
        }
    }
}