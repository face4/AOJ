/**
 * ALDS1_2_A Bubble Sort
 */

import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());
        int[] array = new int[n];
        String[] input = sc.nextLine().split(" ");
        
        for(int i = 0; i < n; i++){
            array[i] = Integer.parseInt(input[i]);
        }

        int count = 0;
        int k = 0;
        while(k < n-1){
            for(int i = n-1; i > k; i--){
                if(array[i] < array[i-1]){
                    int tmp = array[i];
                    array[i] = array[i-1];
                    array[i-1] = tmp;
                    count++;
                }
            }
            k++;
        }

        StringBuilder sb = new StringBuilder();

        for(int i : array)
            sb.append(i + " ");
        
        sb.deleteCharAt(sb.length()-1);

        System.out.println(sb);
        System.out.println(count);
    }
}