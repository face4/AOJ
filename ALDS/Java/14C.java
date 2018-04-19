/**
 * ALDS1_4_C Dictionary
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Set<String> dict = new HashSet<>();
        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            String[] input = br.readLine().split(" ");

            if(input[0].charAt(0) == 'i'){
                dict.add(input[1]);
            }else if(input[0].charAt(0) == 'f'){
                if(dict.contains(input[1])){
                    System.out.println("yes");
                }else{
                    System.out.println("no");
                }
            }
        }

    }
}