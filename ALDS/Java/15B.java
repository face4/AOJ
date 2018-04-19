/**
 * ALDS1_5_B Merge Sort
 */

import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;

class Main {
    static int compare = 0;

    static void merge(int[] A, int left, int mid, int right){
        int l1 = mid-left;
        int l2 = right-mid;

        int[] L = new int[l1+1];
        int[] R = new int[l2+1];

        for(int i = 0; i < l1; i++)
            L[i] = A[left + i];

        for(int i = 0; i < l2; i++)
            R[i] = A[mid + i];

        L[l1] = R[l2] = 1000000001; // Sの要素より確実に大きいInfのようなものを番兵として扱う

        int i = 0;
        int j = 0;

        for(int k = left; k < right; k++){
            compare++;

            if(L[i] <= R[j]){
                A[k] = L[i];
                i++;
            }else{
                A[k] = R[j];
                j++;
            }

        }
    }

    static void mergeSort(int[] A, int left, int right) {
        if (left + 1 < right) {
            int mid = (left + right) / 2;
            mergeSort(A, left, mid);
            mergeSort(A, mid, right);
            merge(A, left, mid, right);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        mergeSort(arr, 0, n);

        StringBuilder sb = new StringBuilder();

        sb.append(arr[0]);

        for(int i = 1; i < n; i++){
            sb.append(" " + arr[i]);
        }

        System.out.println(sb.toString());
        System.out.println(compare);
    }
}