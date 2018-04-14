/**
 * ITP1_9_D Transformation
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        int num = Integer.parseInt(br.readLine());

        for(int i = 0; i < num; i++){
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[1]);
            int b = Integer.parseInt(input[2]);

            switch(input[0]){
                case "print":
                    System.out.println(str.substring(a , b+1));
                    break;
                case "reverse":
                    int cycle = (b-a)/2;
                    char[] hoge = str.toCharArray();
                    for(int j = 0; j <= cycle; j++){
                        char tmp = str.charAt(a+j);
                        hoge[a+j] = hoge[b-j];
                        hoge[b-j] = tmp;
                    }
                    str = String.valueOf(hoge);
                break;
                case "replace": 
                    StringBuilder sb = new StringBuilder(str);
                    sb.replace(a , b+1 , input[3]);
                    str = sb.toString();
                break;
            }
        }

    }
}