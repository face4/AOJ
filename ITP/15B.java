/**
 * ITP1_5_B Print a Frame
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = br.readLine();

        while(!(line.equals("0 0"))){
            String[] inputs = line.split(" ");
            int height = Integer.valueOf(inputs[0]);
            int width = Integer.valueOf(inputs[1]);
            StringBuilder result = new StringBuilder();

            for(int i = 0; i < height; i++){
                if(i == 0 || i == height-1){
                    for(int j = 0; j < width; j++) result.append("#");
                }else{
                    for(int j = 0; j < width; j++){
                        if(j == 0 || j == width-1) result.append("#");
                        else result.append(".");
                    }
                }
                result.append("\n");
            }

            System.out.println(result);
            
            line = br.readLine();
        }

    }
}