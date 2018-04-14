/**
 * ITP1_7_A Grading
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while((line = br.readLine()) != null){
            String[] input = line.split(" ");
            
            if(input[0].equals("-1") && input[1].equals("-1")){
                break;
            }
            
            if(input[0].equals("-1") || input[1].equals("-1")){
                System.out.println("F");
                continue;
            }

            int score = Integer.parseInt(input[0]) + Integer.parseInt(input[1]);

            if(score < 30){
                System.out.println("F");
            }else if(score >= 80){
                System.out.println("A");
            }else if(score < 50){
                if(Integer.parseInt(input[2]) >= 50) System.out.println("C");
                else System.out.println("D");
            }else if(score < 65){
                System.out.println("C");
            }else{
                System.out.println("B");
            }

        }

    }
}