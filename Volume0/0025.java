/**
 * 0025 Hit and Blow
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input;
        int hit = 0;
        int blow = 0;

        while((input = br.readLine()) != null){
            String[] a = input.split(" ");
            String[] b = br.readLine().split(" ");

            hi:
            for(int i = 0; i < 4; i++){
                if(a[i].equals(b[i])){
                    hit++;
                    a[i] = "";
                    b[i] = "";
                }
            }

            bl:
            for(int i = 0; i < 4; i++){
                if(a[i].equals("")){
                    continue bl;
                }

                for(int j = 0; j < 4; j++){
                    if(a[i].equals(b[j])){
                        blow++;
                    }
                }
            }

            System.out.printf("%d %d%n", hit, blow);
            hit = 0;
            blow = 0;
        }
    }
}