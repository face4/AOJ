
/**
 * ALDS1_6_B Partition
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        String[] input = br.readLine().split(" ");

        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(input[i]);
        }

        int pivot = partition(arr, 0, n-1);

        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i < n; i++){
            if(i == pivot){
                sb.append("[").append(arr[i]).append("] ");
            }else{
                sb.append(arr[i]).append(" ");
            }
        }

        System.out.println(sb.toString().trim());
    }

    static int partition(int[] A, int p, int r){
        int x = A[r];
        int i = p-1;

        for(int j = p; j < r; j++){
            if(A[j] <= x){
                i++;
                swap(A, i, j);
            }
        }
        
        swap(A, i+1, r);

        return i+1;
    }

    static void swap(int[] A , int x, int y){
        int tmp = A[x];
        A[x] = A[y];
        A[y] = tmp;
    }

}