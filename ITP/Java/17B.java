/**
 * ITP1_7_B How many ways?
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while((line = br.readLine()) != null){
            String[] input = line.split(" ");
            int max = Integer.valueOf(input[0]);
            int goal = Integer.valueOf(input[1]);
            if(max == 0 && goal == 0) break;
            int count = 0;

            for(int i = 1; i <= max; i++){
                for(int j = 1; j <= max; j++){
                    if(i == j) continue;
                    for(int k = 1; k <= max; k++){
                        if(i == k || j == k) continue;
                        if((i+j+k) == goal) count++;
                    }
                }
            }

            System.out.println(count/6);
        }
    }
}