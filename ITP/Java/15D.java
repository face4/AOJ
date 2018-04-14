/**
 * ITP1_5_D Structured Programming
 */
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int max = sc.nextInt();

        main:
        for(int i = 1; i <= max; i++){
            //multiples of 3
            if(i % 3 == 0){
                sb.append(" " + i);
                continue main;
            }

            int keta = (int)Math.log10(i);
            int tmp = i;

            for(int j = keta; j >= 0; j--){
                int zeros = (int)Math.pow(10 , j);
                int kurai = tmp/zeros;
                
                if(kurai == 3){
                    sb.append(" " + i);
                    continue main;
                }

                tmp -= zeros*kurai;
            }
            
        }

        System.out.println(sb);
    }
    
}