/**
 * ITP1_6_B Finding Missing Cards
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    
    static int getMark(String mark){
        switch(mark){
            case "S":   return 0;
            case "H":   return 1;
            case "C":   return 2;
            case "D":   return 3;
            default :   return -1;
        }
    }

    static String getMark(int mark){
        switch(mark){
            case 0:   return "S";
            case 1:   return "H";
            case 2:   return "C";
            case 3:   return "D";
            default :   return "";
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] cards = new int[4][13];

        int num = Integer.parseInt(br.readLine());

        for(int i = 0; i < num; i++){
            String[] input = br.readLine().split(" ");
            
            int mark = getMark(input[0]);

            cards[mark][Integer.parseInt(input[1])-1] = 1;
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 13; j++){
                if(cards[i][j] == 0) System.out.println(getMark(i) + " " + (j+1));
            }
        }

    }
}