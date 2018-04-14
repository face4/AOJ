import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int num = Integer.valueOf(br.readLine());

        String[] preValues = br.readLine().split(" " , num);
        long[] values = new long[num];

        for(int i = 0; i < num; i++){
            values[i] = Integer.parseInt(preValues[i]);
        }

        System.out.print(getMin(values) + " ");
        System.out.print(getMax(values) + " ");
        System.out.println(sum(values));

    }

    private static long getMin(long[] data){
        long min = data[0];

        for(int i = 1; i < data.length; i++){
            if(min > data[i]) min = data[i];
        }

        return min;
    }

    private static long getMax(long[] data){
        long max = data[0];

        for(int i = 1; i < data.length; i++){
            if(max < data[i]) max = data[i];
        }

        return max;
    }

    private static long sum(long[] data){
        long sum = 0;

        for(int i = 0; i < data.length; i++){
            sum += data[i];
        }

        return sum;
    }

}