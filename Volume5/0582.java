/**
 * 0582-Triangle Types
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.Arrays;

public class Main0582{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int san = 0;
        int cho = 0;
        int ei = 0;
        int don = 0;
        String line;

        while((line = br.readLine()) != null){
            String[] input = line.split(" " , 3);
            int[] sides = new int[3];
            
            for(int i = 0; i < 3; i++)  sides[i] = Integer.parseInt(input[i]);

            boolean isTriangle = (sides[0]+sides[1]>sides[2]) && (sides[1]+sides[2]>sides[0]) && (sides[2]+sides[0]>sides[1]);

            if(isTriangle){
                san++;
                Arrays.sort(sides);
                for(int i = 0; i < 3; i++)  sides[i] = sides[i] * sides[i];

                if(sides[0] + sides[1] < sides[2])      don++;
                else if(sides[0] + sides[1] > sides[2]) ei++;
                else cho++;

            }else{
                break;
            }

        }

        System.out.println(san + " " + cho + " " + ei + " " + don);
    }
}