/**
 * ALDS1_5_A Exhausive Search
 */

import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;

class Main{
    static int[] numbers;
    static int n;

    static boolean check(int index, int sum){
        if(sum == 0){
            return true;
        }

        if(index >= n){
            return false;
        }

        boolean result = check(index+1, sum) || check(index+1, sum-numbers[index]);
        return result;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        numbers = new int[n];
        String[] inputn = br.readLine().split(" ");
        
        for(int i = 0; i < n; i++){
            numbers[i] = Integer.parseInt(inputn[i]);
        }

        int q = Integer.parseInt(br.readLine());
        String[] inputs = br.readLine().split(" ");

        for(int i = 0; i < q; i++){
            if(check(0,Integer.parseInt(inputs[i]))){
                System.out.println("yes");
            }else{
                System.out.println("no");
            }
        }

    }
}