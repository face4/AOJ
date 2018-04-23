
/**
 * 0199 Chairs Where Demanding People Sit
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
    static char[] chair;
    static int n;
    static int[] dist;

    static void sit(String nation) {
        switch (nation) {
        case "A":
            sit_a();
            return;
        case "B":
            sit_b();
            return;
        case "C":
            sit_c();
            return;
        case "D":
            sit_d();
            return;
        }
    }

    static void sit_a() {
        for (int i = 0; i < n; i++) {
            if (chair[i] == '#') {
                chair[i] = 'A';
                return;
            }
        }
    }

    static void sit_b() {
        for (int i = n - 1; i >= 0; i--) {
            if (chair[i] == '#') {
                if (!nextToA(i)) {
                    chair[i] = 'B';
                    return;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (chair[i] == '#') {
                chair[i] = 'B';
                return;
            }
        }
    }

    static void sit_c() {
        if (isEmpty()) {
            chair[n / 2] = 'C';
            return;
        } else {
            for (int i = 0; i < n - 1; i++) {
                if (chair[i] != '#') {
                    if (chair[i + 1] == '#') {
                        chair[i + 1] = 'C';
                        return;
                    }
                    if (i != 0 && chair[i - 1] == '#') {
                        chair[i - 1] = 'C';
                        return;
                    }
                }
            }
        }
    }

    static void sit_d() {
        if (isEmpty()) {
            chair[0] = 'D';
            return;
        } else {
            calcDist();
            int maxIndex = 0;
            int maxValue = Integer.MIN_VALUE;
            for (int j = 0; j < n; j++) {
                if (dist[j] > 0 && maxValue < dist[j]) {
                    maxIndex = j;
                    maxValue = dist[j];
                }
            }

            chair[maxIndex] = 'D';
            return;
        }
    }

    static void calcDist() {
        boolean isFirst = true;
        for (int i = 0; i < n; i++) {
            if (chair[i] != '#') {
                if (isFirst) {
                    dist[i] = -1;
                    for (int j = i - 1; j >= 0; j--) {
                        dist[j] = i - j;
                    }
                    for (int j = i + 1; j < n; j++) {
                        dist[j] = j - i;
                    }
                    isFirst = false;
                } else {
                    dist[i] = -1;
                    for (int j = i - 1; j >= 0; j--) {
                        dist[j] = Math.min(dist[j], i - j);
                    }
                    for (int j = i + 1; j < n; j++) {
                        dist[j] = Math.min(dist[j], j - i);
                    }
                }
            }
        }
    }

    static boolean isEmpty() {
        for (char c : chair) {
            if (c != '#')
                return false;
        }
        return true;
    }

    static boolean nextToA(int i) {
        if (i == 0) {
            return chair[1] == 'A';
        } else if (i == n - 1) {
            return chair[n - 2] == 'A';
        } else {
            return (chair[i - 1] == 'A' || chair[i + 1] == 'A');
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (!(line = br.readLine()).equals("0 0")) {
            String[] input = line.split(" ");
            ;
            n = Integer.parseInt(input[0]);
            chair = new char[n];
            dist = new int[n];
            Arrays.fill(chair, '#');
            int m = Integer.parseInt(input[1]);
            for (int i = 0; i < m; i++) {
                sit(br.readLine());
            }

            for (char c : chair) {
                System.out.print(c);
            }
            System.out.println();
        }
    }
}