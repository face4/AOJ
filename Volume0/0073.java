/**
 * 0073 Surface Area of Quadrangular Pyramid
 */ 

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
            double x = Double.parseDouble(br.readLine());
            double h = Double.parseDouble(br.readLine());
            
            if(x == 0 && h == 0) break;

            double surface = x * x + 2 * x * Math.sqrt(x*x/4 + h*h);

            System.out.printf("%.6f\n",surface);
        }
    }
}