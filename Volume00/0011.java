/**
 * 0011-Drawing Lots
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int w = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());

        int[] array = new int[w];
        for(int i = 0; i < w; i++){
            array[i] = i+1;
        }

        for(int i = 0; i < n; i++){
           String[] input = br.readLine().split(",");
           int a = Integer.parseInt(input[0]);
           int b = Integer.parseInt(input[1]); 
           
           int tmp = array[a-1];
           array[a-1] = array[b-1];
           array[b-1] = tmp;
        }

        for(int i : array){
            System.out.println(i);
        }
    }
}