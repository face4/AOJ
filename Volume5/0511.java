/**
 * 0511-Who Are The Student Yet To Submit
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main0511{
    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int[] data = new int[30];

        for(int i = 0; i < 28; i++){
            data[Integer.valueOf(br.readLine()) - 1] = 1;
        }

        for(int i = 0; i < 30; i++){
            if(data[i] == 0)    System.out.println(i+1);
        }
        
    }
}