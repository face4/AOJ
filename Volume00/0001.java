/**
 * 0001-List of Top 3 Hills
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] data = new int[10];
        
        for(int i = 0; i < 10; i++){
            data[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(data);

        for(int i = 9; i >= 7; i--){
            System.out.println(data[i]);
        }

    }
}