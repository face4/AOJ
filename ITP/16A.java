/**
 * ITP1_6_A Reversing Numbers
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int num = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" " , num);
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < num; i++){
            sb.append(input[num-1-i] + " ");
        }

        System.out.println(sb.toString().substring(0 , sb.toString().length()-1));
    }
}