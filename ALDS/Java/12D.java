
/**
 * ALDS1_2_D Shell Sort
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    static int cnt = 0;

    static void insertionSort(int[] A, int n, int g) {
        for (int i = g; i < n; i++) {
            int v = A[i];
            int j = i - g;
            while(j >= 0 && A[j] > v){
                A[j+g] = A[j];
                j -= g;
                cnt++;
            }
            A[j+g] = v;
        }
    }

    static void shellSort(int[] A, int n){
        int[] G = new int[15];
        int h = 1;
        int m = 0;
        
        for(int i = 1; i <= n; i = i*3 + 1){
            G[m] = i; // シェルソートの幅はこれが良いとされているらしい(Knuth)
            m++;
        }
        System.out.println(m);

        for(int i = m-1; i >= 0; i--){
            System.out.print((i == m-1 ? "" : " ") + G[i] + (i == 0 ? "\n" : ""));
        }

        for(int i = m-1; i >= 0; i--){
            insertionSort(A, n, G[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] array = new int[n];

        for (int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(br.readLine());
        }

        shellSort(array, n);

        System.out.println(cnt);
        for(int i : array){
            System.out.println(i);
        }
    }
}