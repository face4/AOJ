/**
 * 0004-Simultaneous Equation
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

import java.math.BigDecimal;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while( (line = br.readLine()) != null ){
            String[] input = line.split(" ");
            double[] data = new double[6];

            for(int i = 0; i < 6; i++){
                data[i] = Double.parseDouble(input[i]);
            }

            double x = (data[2]*data[4] - data[1]*data[5]) /
                       (data[4]*data[0] - data[1]*data[3]);
            double y = (data[0]*data[5] - data[3]*data[2]) /
                       (data[4]*data[0] - data[1]*data[3]);
            
            BigDecimal a = new BigDecimal(x);
            BigDecimal b = new BigDecimal(y);

            a = a.setScale(3 , BigDecimal.ROUND_HALF_UP);
            b = b.setScale(3 , BigDecimal.ROUND_HALF_UP);
            System.out.println(a + " " + b);

        }
    }
}