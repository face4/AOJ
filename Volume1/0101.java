/**
 * 0101-Aizu PR
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(br.readLine());
        
        for(int i = 0; i < count; i++){
            System.out.println(br.readLine().replaceAll("Hoshino" , "Hoshina"));
        }
        
    }
}