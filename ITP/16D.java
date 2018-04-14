/**
 * ITP1_6_D Matrix Vector Multiplication
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
        String[] input = br.readLine().split(" ");
        int var = Integer.parseInt(input[0]);
        int hor = Integer.parseInt(input[1]);

        int[][] matrix = new int[var][hor];
        int[] vector = new int[hor];
        
        //data input
        for(int i = 0; i < var; i++){
            String[] line = br.readLine().split(" ");
            for(int j = 0; j < hor; j++){
                matrix[i][j] = Integer.parseInt(line[j]);
            }
        }
        for(int i = 0; i < hor; i++){
            vector[i] = Integer.parseInt(br.readLine());
        }
        
        //data output
        for(int i = 0; i < var; i++){
            int result = 0;
            for(int j = 0; j < hor; j++){
                result += matrix[i][j] * vector[j];
            }
            System.out.println(result);
        }

    }
}