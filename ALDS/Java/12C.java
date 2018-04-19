/**
 * ALDS1_2_C Stable Sort
 */

import java.util.Scanner;

class Main{

    static void print(String[] s){
        for(int i = 0; i < s.length; i++){
            System.out.print((i == 0 ? "" : " ") + s[i]);
        }
        System.out.println();
    }

    static boolean isSame(String[] a, String[] b){
        for(int i = 0; i < a.length; i++){
            if(!a[i].equals(b[i]))  return false;
        }
        return true;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());
        String[] array = sc.nextLine().split(" ");

        sc.close();

        String[] arrayB = array.clone();
        String[] arrayS = array.clone();

        int k = 0;
        while(k < n-1){
            for(int i = n-1; i > k; i--){
                if((int)(arrayB[i].charAt(1)) < (int)(arrayB[i-1].charAt(1))){
                    String tmp = arrayB[i];
                    arrayB[i] = arrayB[i-1];
                    arrayB[i-1] = tmp;
                }
            }
            k++;
        }

        print(arrayB);
        System.out.println("Stable");

        for(int i = 0; i < n; i++){
            int minj = i;
            for(int j = i; j < n; j++){
                if((int)(arrayS[j].charAt(1)) < (int)(arrayS[minj].charAt(1))){
                    minj = j;
                }
            }
            if(i != minj){
                String tmp = arrayS[i];
                arrayS[i] = arrayS[minj];
                arrayS[minj] = tmp;
            }
        }

        print(arrayS);
        if(isSame(arrayS,arrayB)){
            System.out.println("Stable");
        }else{
            System.out.println("Not stable");
        }
        
    }
}