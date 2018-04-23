/**
 * 1000-A+B Problem
 */
import java.io.*;

public class Main1000{
    public static void main(String[] args){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = null;

        try{
            line = br.readLine();
        }catch(IOException e){ 
            System.out.println(e);
        }

        while(line != null){
            String[] dataS = new String[2];
            dataS = line.split(" " , 2);

            int[] dataI = new int[2];
            
            for(int i = 0; i < 2; i++){
                dataI[i] = Integer.parseInt(dataS[i]);
            }

            System.out.println(dataI[0] + dataI[1]);
            try{
                line = br.readLine();
            }catch(IOException e){
                System.out.println(e);
            }
    }
    }
}