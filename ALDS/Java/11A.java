/**
 * ALDS1_1_A Insertion Sort
 */
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" " , n);
        int[] array = new int[n];
        
        for(int i = 0; i < n; i++){
            array[i] = Integer.parseInt(input[i]);
        }

        insertionSort(array);

    }

    static void insertionSort(int[] A){
        int N = A.length;

        //output
        StringBuilder sb = new StringBuilder();
        for(int k : A){
            sb.append(k + " ");
        }
        System.out.println(sb.toString().substring(0 , sb.length() - 1));

        for(int i = 1; i < N; i++){
            int v = A[i];
            int j = i-1;
            while(j>=0 && A[j] > v){
                A[j+1] = A[j];
                j--;

            }
            A[j+1] = v;

            //output
            StringBuilder sbs = new StringBuilder();
            for(int k : A){
                sbs.append(k + " ");
            }
            System.out.println(sbs.toString().substring(0 , sbs.length() - 1));

        }
    }

}