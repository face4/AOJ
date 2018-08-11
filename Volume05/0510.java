/**
 * 0510-Score
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class Main0510{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] scores = new int[2];

        for(int i = 0; i < 2; i++){
            String line = br.readLine();
            scores[i] = getScore(line);
        }

        int result;
        if(scores[0] == scores[1]){
            result = scores[0];
        }else{
            result = (scores[0] < scores[1])? scores[1] : scores[0];
        }

        System.out.println(result);
    }

    public static int getScore(String line){
        String[] scores = line.split(" " , 4);
        int score = 0;

        for(int i = 0; i < 4; i++){
            score += Integer.valueOf(scores[i]);
        }

        return score;
    }
    
}