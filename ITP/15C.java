/**
 * ITP1_5_C Print a Chessboard
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = br.readLine();

        while(!(line.equals("0 0"))){
            String[] input = line.split(" ");
            int h = Integer.valueOf(input[0]);
            int w = Integer.valueOf(input[1]);
            StringBuilder sb = new StringBuilder();

            for(int i = 0; i < h; i++){
                boolean which = i%2 == 0;
                for(int j = 0; j < w; j++){
                    if(which) sb.append("#");
                    else sb.append(".");
                    which = !which;
                }
                sb.append("\n");
            }

            System.out.println(sb);
            
            line = br.readLine();
        }

    }
}