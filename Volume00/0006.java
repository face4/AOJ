/**
 * 0006-Reverse Sequence
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();

        for(int i = 0; i < line.length(); i++){
            System.out.print(line.charAt(line.length()-i-1));
        }

        System.out.println();
    }

}