/**
 * ALDS1_2_B Selection Sort
 */

import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());
        String[] input = sc.nextLine().split(" ");
        int[] array = new int[n];
        
        for(int i = 0; i < n; i++){
            array[i] = Integer.parseInt(input[i]);
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            int minj = i;
            for(int j = i; j < n; j++){
                if(array[j] < array[minj]){
                    minj = j;
                }
            }
            if(i != minj){
                int tmp = array[i];
                array[i] = array[minj];
                array[minj] = tmp;
                count++;
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i : array){
            sb.append(i + " ");
        }

        System.out.println(sb.deleteCharAt(sb.length()-1));
        System.out.println(count);
        
    }
}