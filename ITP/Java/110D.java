/**
 * ITP1_10_D Distance II
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int x = Integer.parseInt(br.readLine());
        double[] vectorA = new double[x];
        double[] vectorB = new double[x];

        String[] input = br.readLine().split(" ");
        for(int i = 0; i < x; i++)  vectorA[i] = Double.parseDouble(input[i]);
        input = br.readLine().split(" ");
        for(int i = 0; i < x; i++)  vectorB[i] = Double.parseDouble(input[i]);

        double d1 = 0;
        double d2 = 0;
        double d3 = 0;
        double dinf = 0;

        for(int i = 0; i < x; i++){ 
            double abs = Math.abs(vectorA[i]-vectorB[i]);
            d1 += abs;
            d2 += Math.pow(abs , 2);
            d3 += Math.pow(abs , 3);
            dinf = Math.max(dinf , abs);
        }

        d2 = Math.sqrt(d2);
        d3 = Math.cbrt(d3);

        System.out.println(d1);
        System.out.println(d2);
        System.out.println(d3);
        System.out.println(dinf);
    }
}