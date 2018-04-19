// time limit exceeded!
// 結局TLEを解消したが、はっきりとした原因はわからない
// データ入力に大きく時間を使っていたため、BufferedReaderをscannerに変えたところAC.
/**
 * ALDS1_6_A Counting Sort
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner; // scannerの方が速い(?)

class Main {
    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scan = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = scan.nextInt(); // Integer.parseInt(br.readLine());

        // String[] input = br.readLine().split(" ");

        int[] from = new int[n];
        int[] to = new int[n];

        int max = 0;

        for (int i = 0; i < n; i++) {
            from[i] = scan.nextInt(); // Integer.parseInt(input[i]);
            max = Math.max(max, from[i]);
        }

        CountingSort(from, to, max);

        StringBuilder sb = new StringBuilder();
        sb.append(to[0]);

        for (int i = 1; i < n; i++)
                sb.append(" " + to[i]);

        System.out.println(sb);
    }

    static void CountingSort(int[] A, int[] B, int k) {
        int[] C = new int[k + 1];
        int length = A.length;

        /*
        for (int i = 0; i < k + 1; i++) 
            C[i] = 0;
        */
        int i; // to avoid TLE

        for (i = 0; i < length; i++) 
            C[A[i]]++;

        for (i = 1; i < k + 1; i++) 
            C[i] += C[i - 1];
        
        for (i = length - 1; i >= 0; i--)
            B[--C[A[i]]] = A[i];
        
    }

}