/**
 * 0512-Caesar Cipher
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main0512{
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();

        for(int i = 0; i < line.length(); i++){
            char a = line.charAt(i);

            for(int j = 0; j < 3; j++){
                if(a == 'A'){
                    a = 'Z';
                }else{
                    a = (char)(a-1);
                }
            }

            System.out.print(a);
        }
        
        System.out.println();
    }

}