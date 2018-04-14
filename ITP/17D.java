/**
 * ITP1_7_D Matrix Multiplication
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] nums = br.readLine().split(" ");
        int n = Integer.parseInt(nums[0]);
        int m = Integer.parseInt(nums[1]);
        int l = Integer.parseInt(nums[2]);

        long[][] matrixA = new long[n][m];
        long[][] matrixB = new long[m][l];
        long[][] matrixC = new long[n][l];

        //input matrixA
        for(int i = 0; i < n; i++){
            String[] input = br.readLine().split(" ");
            for(int j = 0; j < m; j++){
                matrixA[i][j] = Long.valueOf(input[j]);
            }
        }

        //input matrixB
        for(int i = 0; i < m; i++){
            String[] input = br.readLine().split(" ");
            for(int j = 0; j < l; j++){
                matrixB[i][j] = Long.valueOf(input[j]);
            }
        }

        //input matrixC(matrixA * matrixB)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < l; j++){
                for(int k = 0; k< m; k++){
                    matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }

        //output matrixC
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < l; j++){
                sb.append(matrixC[i][j]);
                if(j != l-1) sb.append(" ");
            }
            if(i != n-1) sb.append("\n");
        }
        System.out.println(sb);

    }
}