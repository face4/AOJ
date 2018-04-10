/**
 * 0066 Tic Tac Toe
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String line;
        
        loop:
        while((line = br.readLine()) != null){
            char[] arr = line.toCharArray();

            // vertical check
            for(int i = 0; i < 3; i++){
                if(arr[i] != 's' && arr[i] == arr[i+3] && arr[i+3] == arr[i+6]){
                    System.out.println(arr[i]);
                    continue loop;
                }
            }

            // horizontal check
            for(int i = 0; i < 3; i++){
                if(arr[3*i] != 's' && arr[3*i] == arr[3*i+1] && arr[3*i+1] == arr[3*i+2]){
                    System.out.println(arr[3*i]);
                    continue loop;
                }
            }

            // oblique check
            if(arr[0] != 's' && arr[0] == arr[4] && arr[4] == arr[8]){
                System.out.println(arr[0]);
                continue loop;
            }
            if(arr[2] != 's' && arr[2] == arr[4] && arr[4] == arr[6]){
                System.out.println(arr[2]);
                continue loop;
            }

            System.out.println("d");
        }
    }
}