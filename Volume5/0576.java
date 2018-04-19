/**
 * 0576-Homework
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main0576{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int day = Integer.parseInt(br.readLine());
        int lang = Integer.parseInt(br.readLine());
        int math = Integer.parseInt(br.readLine());
        int langAb = Integer.parseInt(br.readLine());
        int mathAb = Integer.parseInt(br.readLine());

        while(lang > 0 || math > 0){
            lang -= langAb;
            math -= mathAb;
            day--;
        }

        System.out.println(day);

    }

}