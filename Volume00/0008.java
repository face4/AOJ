/**
 * 0008-Sum of 4 Integers
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while( (line = br.readLine()) != null){
            int a = Integer.parseInt(line);
            int count = 0;

            if(a > 36){
                System.out.println(count);
                continue;
            }

            for(int i = 9; i >= 0; i--){
                for(int j = 9; j >= 0; j--){
                    for(int k = 9; k>= 0; k--){
                        for(int l = 9; l >= 0; l--){
                            if(i+j+k+l == a) count++;
                        }
                    }
                }
            }

            System.out.println(count);
        }

    }
}