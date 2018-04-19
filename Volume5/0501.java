/**
 * 0501-Data Conversion
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main0501{
    public static void main(String[] args){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp;
        int tablenum;

        try{
            while((tablenum = Integer.valueOf(tmp = br.readLine())) != 0) {
                String[][] table = new String[tablenum][2];
                
                for(int i = 0; i < tablenum; i++){
                    table[i] = br.readLine().split(" " , 2);
                }

                int inputnum = Integer.valueOf(br.readLine());

                outer:
                for(int i = 0; i < inputnum; i++){
                    String tmps = br.readLine();
                    for(int j = 0; j < tablenum; j++){
                        if(tmps.equals(table[j][0])){
                            System.out.print(table[j][1]);
                            continue outer;
                        }
                    }
                    System.out.print(tmps);
                }

                System.out.println();
            }
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}