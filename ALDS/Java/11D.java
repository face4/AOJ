/**
 * ALDS1_1_D Maximum Profit
 */

import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.next());

        int r0 = Integer.parseInt(sc.next());
        int r1 = Integer.parseInt(sc.next());

        int max = r1-r0;
        int min = Math.min(r0,r1);

        for(int i = 2; i < n; i++){
            int r = Integer.parseInt(sc.next());
            max = Math.max(max, r - min);
            min = Math.min(min,r);
        }
        
        System.out.println(max);
    }
}