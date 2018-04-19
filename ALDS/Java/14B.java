/**
 * ALDS 1_4_B Binary Search
 */

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main {

    static boolean binarySearch(int[] a, int key, int begin, int end){     
        if(begin >= end){
            if(a[begin] != key){
                return false;
            }
        }

        int med = (begin + end) / 2;
        if (a[med] == key) {
            return true;
        } else if (a[med] > key) {
            return binarySearch(a, key, begin, med - 1);
        } else if (a[med] < key) {
            return binarySearch(a, key, med + 1, end);
        }

        return false; // unreachable
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int result = 0;

        int n = Integer.parseInt(br.readLine());
        int[] S = new int[n];
        String[] inputs = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            S[i] = Integer.parseInt(inputs[i]);
        }

        int q = Integer.parseInt(br.readLine());
        String[] inputt = br.readLine().split(" ");
        for (String str : inputt) {
            if (binarySearch(S, Integer.parseInt(str), 0, n - 1)) {
                result++;
            }
        }

        System.out.println(result);
    }
}