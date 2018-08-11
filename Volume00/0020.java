/**
 * 0020-Capitalize
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = br.readLine();

        System.out.println(line.toUpperCase());
    }
}