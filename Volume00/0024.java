/**
 * 0024-Physical Experiments
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while( (line = br.readLine()) != null){
            double v = Double.parseDouble(line);
            int f = 0;
            while(true){
                f++;
                double height = 5*f - 5;
                double t = Math.sqrt(height / 4.9);
                double vReal = 9.8 * t;
                if(vReal >= v)  break;
            }
            System.out.println(f);
        }

    }
}