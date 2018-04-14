/**
 * ITP1_9_B Shuffle
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    static String shuffle(String origin , int h){
        return origin.substring(h , origin.length()) + origin.substring(0 , h);
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while(!(line=br.readLine()).equals("-")){
            int times = Integer.parseInt(br.readLine());
            for(int i = 0; i < times; i++){
                line = shuffle(line , Integer.parseInt(br.readLine()));
            }
            System.out.println(line);
        }

    }
}