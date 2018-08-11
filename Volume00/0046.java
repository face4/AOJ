/**
 * 0046 Differential
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        double max = Double.MIN_VALUE;
        double min = Double.MAX_VALUE;

        String line;

        while((line = br.readLine()) != null){
            Double height = Double.parseDouble(line);
            max = Math.max(height,max);
            min = Math.min(height,min);
        }

        System.out.println((max-min));
    }
}