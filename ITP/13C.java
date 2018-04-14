/**
 * ITP1_3_C Swapping Two Numbers
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while( ((line = br.readLine()) != null) && !(line.equals("0 0"))){
            String[] input = line.split(" " , 2);
            int a = Integer.valueOf(input[0]);
            int b = Integer.valueOf(input[1]);
            if(a > b)   System.out.println(b + " " + a);
            else        System.out.println(a + " " + b);
        }
    }
}