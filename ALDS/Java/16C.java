
/**
 * ALDS1_6_C Quick Sort
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static String[] cards;
    static int[] nums;
    static int[] check; // stable or not stable
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        cards = new String[n];
        nums = new int[n];
        check = new int[n];

        for (int i = 0; i < n; i++) {
            cards[i] = br.readLine();
            nums[i] = Integer.parseInt(cards[i].split(" ")[1]);
            check[i] = i;
        }

        quickSort(nums, 0, n - 1);

        if (isStable()) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }

        for (String s : cards) {
            System.out.println(s);
        }

    }

    static boolean isStable() {
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]){
                if(check[i] > check[i+1]){
                    return false;
                }
            }
        }
        return true;
    }

    static void quickSort(int[] A, int p, int r) {
        if (p < r) {
            int q = partition(A, p, r);
            quickSort(A, p, q - 1);
            quickSort(A, q + 1, r);
        }
    }

    static int partition(int[] A, int p, int r) {
        int x = A[r];
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (A[j] <= x) {
                i++;
                swap(A, i, j);
            }
        }
        swap(A, i + 1, r);
        return i + 1;
    }

    static void swap(int[] A, int x, int y) {
        int tmp = A[x];
        A[x] = A[y];
        A[y] = tmp;

        String tmps = cards[x];
        cards[x] = cards[y];
        cards[y] = tmps;

        tmp = check[x];
        check[x] = check[y];
        check[y] = tmp;
    }

}
