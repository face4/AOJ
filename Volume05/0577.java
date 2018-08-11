/**
 * 0577-Unique number
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main0577{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int player = Integer.valueOf(br.readLine());

        int[][] input = new int[player][3];

        for(int i = 0; i < player; i++){
            String[] line = br.readLine().split(" " , 3);

            for(int j = 0; j < 3; j++){
                input[i][j] = Integer.valueOf(line[j]);
            }

        }

        for(int i = 0; i < 3; i++){ 
            for(int j = 0; j < player-1; j++){
                int now = input[j][i];
                for(int k = j+1; k < player; k++){
                    if(now == input[k][i]) input[j][i] = input[k][i] = 0;
                }
            }
        }

        for(int i = 0; i < player; i++){
            System.out.println(input[i][0] + input[i][1] + input[i][2]);
        }
    }
}