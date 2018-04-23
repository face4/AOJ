/**
 * 0642 Sugoroku
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");

        int max = 0;
        boolean onCheck = false;
        int cl = 1; // current length

        for(String x : input){
            if(x.equals("1")){
                cl++;
                onCheck = true;
            }else if(onCheck){
                max = Math.max(cl,max);
                cl = 1;
                onCheck = false;
            }
        }

        max = Math.max(cl,max);

        System.out.println(max);
    }
}