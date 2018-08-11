/**
 * 0013-Switching Railload Cars
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        int[] cars = new int[10];
        int pos = -1;

        while( (line = br.readLine()) != null){
            int a = Integer.parseInt(line);
            if(a != 0){
                pos++;
                cars[pos] = a;
            }else{
                System.out.println(cars[pos]);
                cars[pos] = 0;
                pos--;
            }
        }

    }
}