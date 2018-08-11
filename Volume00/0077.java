/**
 * 0077 Run Length
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String line;
        
        while((line = br.readLine()) != null){
            StringBuilder sb = new StringBuilder();
            int index = 0;
            while(index < line.length()){
                char c = line.charAt(index);
                if(c == '@'){
                    int times = (int)(line.charAt(++index) - '0');
                    char repeat = line.charAt(++index);
                    for(int i = 0; i < times; i++){
                        sb.append(repeat);
                    }
                }else{
                    sb.append(c);
                }
                index++;
            }
            System.out.println(sb);
        }
    }
}