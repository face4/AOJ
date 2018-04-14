/**
 * ITP1_8_D Ring
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] s = br.readLine().toCharArray();
        char[] p = br.readLine().toCharArray();
        boolean result = false;
        
        main:
        for(int i = 0; i < s.length; i++){
            for(int j = 0; j < p.length; j++){
                int index = i+j;
                if(index >= s.length) index -= s.length;
                if(!(s[index] == p[j])) continue main;
            }
            result = true;
        }

        if(result)  System.out.println("Yes");
        else System.out.println("No");

    }
}