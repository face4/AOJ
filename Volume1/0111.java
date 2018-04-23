// 0111 何が間違ってるのかよくわかんね！
/**
 * 0111 Doctor's Memorable Codes
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    static String dec(char x){
        if('A' <= x && x <= 'Z'){
            return String.format("%5s",Integer.toBinaryString((int)(x - 'A'))).replaceAll(" ","0");
        }else if(x == ' '){
            return "11010";
        }else if(x == '.'){
            return "11011";
        }else if(x == ','){
            return "11100";
        }else if(x == '-'){
            return "11101";
        }else if(x == '\''){
            return "11110";
        }else if(x == '?'){
            return "11111";
        }

        return null; // unreachable
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = { " ", "\'", ",", "-", ".", "?", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
        String[] f = { "101", "000000", "000011", "10010001", "010001", "000001", "100101", "10011010", "0101", "0001",
                "110", "01001", "10011011", "010000", "0111", "10011000", "0110", "00100", "10011001", "10011110",
                "00101", "111", "10011111", "1000", "00110", "00111", "10011100", "10011101", "000010", "10010010",
                "10010011", "10010000" };
        
        String line;

        while((line = br.readLine()) != null){
            StringBuilder tmp = new StringBuilder();
            for(char c : line.toCharArray()){
                tmp.append(dec(c));
            }
            line = tmp.toString();

            StringBuilder ans = new StringBuilder();

            while(line.length() >= 5){
                String substr = line.substring(0,5);
                for(int i = 0; i < f.length; i++){
                    if(substr.startsWith(f[i]) || (f[i].startsWith(substr) && line.startsWith(f[i]))){
                        // System.out.println(substr + " に対して " + f[i] + "が見つかったので" + s[i] + "を出力.");
                        ans.append(s[i]);
                        line = line.substring(f[i].length());
                        break;
                    }
                }
            }

            System.out.println(ans);
        }
    }
}