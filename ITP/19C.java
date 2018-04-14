/**
 * ITP1_9_C Card Game
 */
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int t = 0;
        int h = 0;

        for(int i = 0; i < n; i++){
            String[] input = br.readLine().split(" ");
            if(input[0].compareTo(input[1]) < 0)        h += 3;
            else if(input[0].compareTo(input[1]) > 0)   t += 3;
            else {
                h++;
                t++;
            }
        }

        System.out.println(t + " " + h);
    }
}