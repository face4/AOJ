/**
 * ITP1_7_C Spreadsheet
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int r = Integer.valueOf(input[0]);
        int c = Integer.valueOf(input[1]);

        int[][] matrix = new int[r+1][c+1];
        
        //input data
        for(int i = 0; i < r; i++){
            String[] line = br.readLine().split(" " , c);
            for(int j = 0; j < c; j++){
                matrix[i][j] = Integer.parseInt(line[j]);
            }
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                matrix[i][c] += matrix[i][j];
            }
        }

        for(int i = 0; i < c+1; i++){
            for(int j = 0; j < r; j++){
                matrix[r][i] += matrix[j][i];
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i <= r; i++){
            for(int j = 0; j <= c; j++){
                sb.append(matrix[i][j]);
                if(j != c) sb.append(" ");
            }
            if(i != r)sb.append("\n");
        }
        System.out.println(sb);

    }
}