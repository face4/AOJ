/**
 * ALDS1_1_C Prime Numbers
 */

import java.util.Scanner;

class Main{

    static boolean isPrime(int n){
        if(n == 2){
            return true;
        }else if(n < 2 || n % 2 == 0){
            return false;
        }else{
            int x = 3;
            while(x <= Math.sqrt((double)n)){
                if(n%x == 0)    return false;
                x += 2;
            }
            return true;
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.next());
        int result = 0;

        for(int i = 0; i < n; i++){
            if(isPrime(Integer.parseInt(sc.next()))) result++;
        }

        System.out.println(result);
    }
}