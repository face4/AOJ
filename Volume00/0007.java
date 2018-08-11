/**
 * 0007-Debt Hell
 */
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double debt = 100000;

        for(int i = 0; i < n; i++){
            debt *= 1.05;
            double s = debt / 1000;
            s = Math.ceil(s);
            debt = s * 1000;
        }

        System.out.println((int)debt);
    }
}