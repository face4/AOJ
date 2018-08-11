/**
 * 0502-Dice
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class Main0502{
    
    public static void main(String[] args){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int times;

        try{
            while((times = Integer.parseInt(br.readLine())) != 0){
                //initialize
                int[] dice = {1,2,3,5,4,6};
                int score = 1;

                for(int i = 0; i < times; i++){
                    rotate(br.readLine() , dice);
                    score += dice[0];
                }

                System.out.println(score);

            }
        }catch(IOException e){
            e.printStackTrace();
        }

    }
    

    private static void rotate (String order , int[] dice){
        int tmp;
        switch(order){
            case "North":
                tmp = dice[0];
                dice[0] = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[3];
                dice[3] = tmp;
                break;
            case "East":
                tmp = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[5];
                dice[5] = dice[2];
                dice[2] = tmp;
                break;
            case "South":
                tmp = dice[0];
                dice[0] = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[1];
                dice[1] = tmp;
                break;
            case "West":
                tmp = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[4];
                dice[4] = tmp;
                break;
            case "Left":
                tmp = dice[1];
                dice[1] = dice[4];
                dice[4] = dice[3];
                dice[3] = dice[2];
                dice[2] = tmp;
                break;
            case "Right":
                tmp = dice[1];
                dice[1] = dice[2];
                dice[2] = dice[3];
                dice[3] = dice[4];
                dice[4] = tmp;
                break;
        }
    }
}