/**
 * 0584 The Third Permutation
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.ArrayList;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] input = new int[n];

        for(int i = 0; i < n; i++){
            input[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(input);

        ArrayList<Integer> al = new ArrayList<Integer>();

        for(int i = 0; i < Math.min(4,n); i++){
            for(int j = 0; j < Math.min(4,n); j++){
                if(i == j) continue;
                al.add(Integer.parseInt(String.valueOf(input[i]) + String.valueOf(input[j])));
            }
        }

        Collections.sort(al);
        System.out.println(al.get(2));
    }
}