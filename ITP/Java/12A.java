/**
 * ITP1_2_A Small,Large,or Equal
 */
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        String result = (a == b) ? "a == b" : (a > b) ? "a > b" : "a < b";
        System.out.println(result);
    }
}