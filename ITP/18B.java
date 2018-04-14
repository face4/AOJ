/**
 * ITP1_8_B Sum of Numbers
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while((line = br.readLine()) != null){
            if(line.equals("0")) break;

            char[] a = line.toCharArray();
            int result = 0;

            for(char c : a){
                result += c - '0';
            }

            System.out.println(result);
        }
    }
}