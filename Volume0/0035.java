// 凹みのある四角形-> 線分ACと直線BD、もしくは線分BDと直線ACのいずれかが交差していない
// http://d.hatena.ne.jp/otaks/20110428/1303979575
// 線分の交差判定
// http://www5d.biglobe.ne.jp/~tomoya03/shtml/algorithm/Intersection.htm

/**
 * 0035 Is it Convex?
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {

    // 直線(x1,y1)(x3,y3)と線分(x2,y2)(x4,y4)の交差判定。
    // (結果 < 0) <=> 交差, (結果 > 0) <=> 交差しない, (結果 = 0) <=> 線分の端点が直線上に存在(今回与えられる入力ではあり得ない)
    static boolean intersec(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        return (((y2 - y1) * (x3 - x1) - (y3 - y1) * (x2 - x1)) * ((y4 - y1) * (x3 - x1) - (y3 - y1) * (x4 - x1)) < 0);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input;

        while ((input = br.readLine()) != null) {
            String[] line = input.split(",");
            double[] p = new double[8];

            for (int i = 0; i < 8; i++) {
                p[i] = Double.parseDouble(line[i]);
            }

            if (intersec(p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7])
                    && intersec(p[6], p[7], p[0], p[1], p[2], p[3], p[4], p[5])) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }

        }
    }
}