/**
 * ITP1_4_C Simple Calculator
 */
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        
        loop:
        while((line = br.readLine()) != null){
            String[] input = line.split(" " , 3);
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[2]);

            switch(input[1]){
                case "?":
                    break loop;
                case "+":
                    System.out.println(a+b);
                    break;
                case "-":
                    System.out.println(a-b);
                    break;
                case "*":
                    System.out.println(a*b);
                    break;
                case "/":
                    System.out.println(a/b);
                    break;
            }

        }

    }
}