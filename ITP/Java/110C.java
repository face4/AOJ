/**
 * ITP1_10_C Standard Deviation
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;

        while(!((line = br.readLine()).equals("0"))){
            int n = Integer.parseInt(line);
            String[] input = br.readLine().split(" ");
            int[] data = new int[n];

            double sum = 0;
            double squaresum = 0;
            double average;

            for(int i = 0; i < n; i++){
                data[i] = Integer.parseInt(input[i]);
                sum += data[i];
            }

            average = sum/n;

            for(int i = 0; i < n; i++){
                squaresum += Math.pow(data[i]-average , 2);
            }

            double variance = squaresum / n;

            System.out.println(Math.sqrt(variance));
        }
    }
}