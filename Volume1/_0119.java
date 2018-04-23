// 証言の順番によって出力が変わってしまう...
/**
 * 0119 Taro's Obsession
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int[] order;

    static void bubble(int i, int j) {
        if (i <= j) { // 本来は不等号のみで良い.等号はtamaPosを変更する処理のために入れた.
            return;
        }

        int tmp = order[i];
        for (int x = i; x > j; x--) {
            order[x] = order[x - 1];
        }
        order[j] = tmp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());

        boolean[] isHuman = new boolean[m + 1];
        order = new int[m];

        for (int i = 0; i < m; i++) {
            order[i] = i + 1;
        }

        int a = 0;
        int b = 0;
        int posA = 0;
        int posB = 0;

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            a = Integer.parseInt(input[0]);
            isHuman[a] = true;
            b = Integer.parseInt(input[1]);
            // 配列を走査、入れ替えの必要性を判断
            for (int j = 0; j < m; j++) {
                if (order[j] == a)
                    posA = j;
                if (order[j] == b)
                    posB = j;
            }
            bubble(posA, posB);
        }

        /*
        // タマを適切な位置に配置
        int tamaNum = 1;
        while (true) {
            if (!isHuman[tamaNum])
                break;
            tamaNum++;
        }
        int tamaPos = 0;
        for (tamaPos = 0; tamaPos < m; tamaPos++) {
            if (order[tamaPos] == tamaNum)
                break;
        }

        System.out.println("tamaPos : " + tamaPos);
        bubble(m - 1, tamaPos);
*/
        // display
        for (int x : order) {
            System.out.println(x);
        }
    }
}