/**
 * ITP1_8_A Toggling Cases
 */
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < line.length() ; i++){
            char now = line.charAt(i);
            if(Character.isUpperCase(now))      sb.append(Character.toLowerCase(now));
            else if(Character.isLowerCase(now)) sb.append(Character.toUpperCase(now));
            else                                sb.append(now);
        }

        System.out.println(sb);

    }
}