/**
 * ITP1_3_B Print Test Cases
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int cycle = 0;
        String line;
        while(!((line = br.readLine()).equals("0"))) 
            System.out.println("case " + ++cycle + ": " + line);
    }
}