/**
 * 0034 Railway Lines
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String input;

        while((input = br.readLine()) != null){
            String[] line = input.split(",");

            int[] distance = new int[12];
            int sum = 0;
            int velA;
            int velB;

            for(int i = 0; i < 10; i++){
                distance[i] = Integer.parseInt(line[i]);
                sum += distance[i];
            }

            velA = Integer.parseInt(line[10]);
            velB = Integer.parseInt(line[11]);

            double intersec = (double)sum / (velA + velB) * velA;

            int forward = 0;
            int pos = 0;
            do{
                forward += distance[pos];
                pos++;
            }while(forward < intersec);

            System.out.println(pos);

        }

    }
}