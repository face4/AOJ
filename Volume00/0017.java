/**
 * 0017-Caesar Cipher
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while( (line = br.readLine()) != null ){
            char[] input = line.toCharArray();

            for(int i = 0; i < 26; i++){
                
                for(int j = 0; j < input.length; j++){
                    if(Character.isLowerCase(input[j])){
                        int a = (input[j] + 1 - 'a') % 26;
                        input[j] = (char)('a' + a);
                    }
                }

                String result = String.valueOf(input);
                
                if(result.indexOf("this") >= 0 || result.indexOf("the") >= 0 || result.indexOf("that") >= 0){
                    System.out.println(result);
                    break;
                }

            }


        }
        
    }
}