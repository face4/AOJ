
/**
 * ALDS1_5_C Koch Curve
 */

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Vector {
    double x;
    double y;

    Vector(double x, double y) {
        this.x = x;
        this.y = y;
    }

    void print() {
        System.out.printf("%.8f %.8f%n", this.x, this.y);
    }

}

class Main {
    static void drawCoch(int depth, Vector start, Vector goal) {
        if (depth == 0) {
            return;
        }

        Vector s = new Vector(2.0 / 3.0 * start.x + 1.0 / 3.0 * goal.x, 2.0 / 3.0 * start.y + 1.0 / 3.0 * goal.y);
        Vector u = new Vector(1.0 / 3.0 * start.x + 2.0 / 3.0 * goal.x, 1.0 / 3.0 * start.y + 2.0 / 3.0 * goal.y);
        Vector t = new Vector(1.0 / 2.0 * (goal.x + start.x) - Math.sqrt(3.0) / 6.0 * (goal.y - start.y),
                            1.0 / 2.0 * (goal.y + start.y) + Math.sqrt(3.0) / 6.0 * (goal.x - start.x));

        drawCoch(depth - 1, start, s);
        s.print();
        drawCoch(depth - 1, s, t);
        t.print();
        drawCoch(depth - 1, t, u);
        u.print();
        drawCoch(depth - 1, u, goal);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Vector start = new Vector(0.0, 0.0);
        Vector goal = new Vector(100.0, 0.0);

        start.print();
        drawCoch(n, start, goal);
        goal.print();
    }
}