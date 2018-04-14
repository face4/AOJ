/**
 * ITP1_1_B X cubic
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println((int)(Math.pow(Integer.parseInt(br.readLine()) , 3)));
    }

}
