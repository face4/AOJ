
/**
 * 0110 Alphametic
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {

    static int dec(char c, int i) {
        if (c == 'X') {
            return i;
        } else {
            return (int) (c - '0');
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while((line = br.readLine()) != null){
            String[] input = line.split("[+=]");
            int limit = 0;
            if((input[0].charAt(0) == 'X' && input[0].length() != 1) ||
            (input[1].charAt(0) == 'X' && input[1].length() != 1) ||
            (input[2].charAt(0) == 'X' && input[2].length() != 1)){
                limit = 1;
            }
            StringBuilder a = new StringBuilder();
            StringBuilder b = new StringBuilder();

            for(int i = 0; i < input[2].length()-input[0].length(); i++){
                a.append("0");
            }   
            a.append(input[0]);
            input[0] = a.toString();

            for(int i = 0; i < input[2].length()-input[1].length(); i++){
                b.append("0");
            }            
            b.append(input[1]);
            input[1] = b.toString();
            
            boolean result = false;
            int ans;
            int carry = 0;

            large:
            for(ans = 9; ans >= limit; ans--){
                carry = 0;
                for(int j = input[2].length() - 1; j >= 0; j--){
                    int m = dec(input[0].charAt(j) , ans);
                    int n = dec(input[1].charAt(j) , ans);
                    int o = dec(input[2].charAt(j) , ans);
                    if((m + n + carry) % 10 != o){
                        continue large;
                    }
                    carry = (m+n+carry)/10;
                }
                result = true;
                break;
            }
            
            if(result && carry == 0){
                System.out.println(ans);
            }else{
                System.out.println("NA");
            }
        }
    }
}