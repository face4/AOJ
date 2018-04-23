
/**
 * 0125 Day Count
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int[] days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    static boolean isLeap(int y) {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    }

    static int yTod(int y) {
        if (isLeap(y))
            return 366;
        else
            return 365;
    }

    static int myTod(int m, int y) {
        if (m == 2 && isLeap(y))
            return 29;
        else
            return days[m];
    }

    static int dmyTod(int d, int m, int y) {
        int res = 0;
        int month = 0;
        while (++month < m) {
            res += myTod(month, y);
        }
        res += d;
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        int y1, m1, d1, y2, m2, d2;
        while ((line = br.readLine()) != null) {
            String[] input = line.split(" ");
            y1 = Integer.parseInt(input[0]);
            m1 = Integer.parseInt(input[1]);
            d1 = Integer.parseInt(input[2]);
            y2 = Integer.parseInt(input[3]);
            m2 = Integer.parseInt(input[4]);
            d2 = Integer.parseInt(input[5]);
            if (y1 < 0 || m1 < 0 || d1 < 0 || y2 < 0 || m2 < 0 || d2 < 0) {
                break;
            }

            long sum = 0;
            if (y1 < y2) {
                sum += yTod(y1) - dmyTod(d1, m1, y1) + 1;
                y1++;
                m1 = 1;
                d1 = 1;
            }

            while (y1 < y2) {
                sum += yTod(y1++);
            }

            sum += dmyTod(d2, m2, y2) - dmyTod(d1, m1, y1);

            System.out.println(sum);
        }
    }
}