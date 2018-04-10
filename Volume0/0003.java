/**
 * 0003-Is it a Right Triangle?
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for(int i= 0; i < n; i++){
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            int c = Integer.parseInt(input[2]);
            
            boolean isRight = false;
            if(a>=c && a>=b)        isRight = (a*a == b*b + c*c);
            else if(b>=c && b>=a)   isRight = (b*b == c*c + a*a);
            else if(c>=a && c>=b)   isRight = (c*c == a*a + b*b);

            if(isRight) System.out.println("YES");
            else        System.out.println("NO");
        }
    }
}

//Arraysのsortを使えばif文のところがもっと綺麗になる。