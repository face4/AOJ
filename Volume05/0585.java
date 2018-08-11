// https://www.ioi-jp.org/joi/2005/2006-m1-prob_and_sol/2006-m1-t4-review.html
// 上の記事のアルゴリズムを採用。枝狩りによる高速化。

// http://ry0u.github.io/blog/2016/03/06/aoj0585-nearest-two-points/
// 上の記事は分割統治法を用いたO(n logn)のアルゴリズム。まだ理解できていない。

/**
 * 0585 Nearest Two Points
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

class Point {
    int x;
    int y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int distance(Point p) {
        return (p.x - this.x)*(p.x - this.x) + (p.y - this.y)*(p.y - this.y);
    }

}

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Point[] p = new Point[n];
        String[] line = new String[2];

        for (int i = 0; i < n; i++) {
            line = br.readLine().split(" ");
            p[i] = new Point(Integer.parseInt(line[0]), Integer.parseInt(line[1]));
        }

        // implements compare by inner class 
        Arrays.sort(p, new Comparator<Point>() {
            public int compare(Point p1, Point p2) {
                return p1.x - p2.x;
            }
        });

        int result = Integer.MAX_VALUE;

        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (p[i].x - p[j].x >= Math.sqrt(result))
                    break;
                result = Math.min(result, p[i].distance(p[j]));
            }
        }

        System.out.println(result);
    }
}
