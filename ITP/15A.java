/**
 * ITP1_5_A Print a Rectangle
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = br.readLine();

        while(line != null){            
            String[] input = line.split(" ");
            int height = Integer.valueOf(input[0]);
            int width = Integer.valueOf(input[1]);
            
            if(height == 0 && width == 0) break;
            
            for(int i = 0; i < height; i++){
                for(int j = 0; j < width; j++){
                    System.out.print("#");
                }
                System.out.println();
            }
            
            System.out.println();
            line = br.readLine();
        }
    }
}