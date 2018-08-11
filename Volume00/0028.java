/**
 * 0028 Mode Value
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int[] data = new int[101]; // data[0]は使わない
        for(int i = 0; i < 101; i++){
            data[i] = 0;
        }

        String input;
        while((input = br.readLine()) != null){
            data[Integer.parseInt(input)]++;
        }

        int max = 0;
        for(int i = 0; i < 101; i++){
            if(data[i] > max){
                max = data[i];
            }
        }

        for(int i = 0; i < 101; i++){
            if(data[i] == max){
                System.out.println(i);
            }
        }
    }
}