/**
 * 0500-Card Game
 */
import java.io.*;

public class Main0500{
    
        static int Ap = 0;
        static int Bp = 0;

    public static void main(String[] args){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        try{
            while(true){
                int a = Integer.parseInt(br.readLine());

                if(a == 0) break;
                
                Ap = Bp = 0;

                for(int i = 0; i < a; i++){
                    String[] tmp = br.readLine().split(" " , 2);
                    int[] points = new int[2];
                    points[0] = Integer.parseInt(tmp[0]);
                    points[1] = Integer.parseInt(tmp[1]);
                    judgement(points);
                }

                System.out.println(Ap + " " + Bp);

            }
        }catch(IOException e){
            e.printStackTrace();
        }

    }

    public static void judgement (int[] p){
        if(p[0] > p[1]){
            Ap += (p[0]+p[1]);
        }else if(p[0] < p[1]){
            Bp += (p[0]+p[1]);
        }else if(p[0] == p[1]){
            Ap += p[0];
            Bp += p[1];
        }
    }
}