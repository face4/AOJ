/**
 * 0506-String
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main0506 {
    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        int count;


        while((count = Integer.parseInt(line = br.readLine())) != 0){
            line = br.readLine();
            StringBuilder result = new StringBuilder();

            for(int i = 0; i < count; i++){
                line = metamorphose(line);
            }

            System.out.println(line);
        }
    }

    private static String metamorphose(String line){
        StringBuilder result = new StringBuilder();
        int count = 1;

        for(int i = 0; i < line.length(); i++){
            char now = line.charAt(i);
            char next = ' ';
            if(i != line.length()-1) next = line.charAt(i+1);
            
            if(i == line.length()-1){
                construct(result,count,now);
                break;
            }

            if(now == next){
                count++;
            }else if(now != next){
                construct(result,count,now);
                count = 1;
            }

        }
        return result.toString();
    }

    private static void construct(StringBuilder result , int count , char now){
                result.append(count); 
                result.append(now);
    }

}