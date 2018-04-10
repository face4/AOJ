// wrong answer. この回答ではa=dが1000以下とは限らない
/**
 * 0096 Sum of 4 Integers II
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            long n = Long.parseLong(line);

            long answer = (n + 3) * (n + 2) * (n + 1) / 3 / 2;

            System.out.println(answer);
        }
    }
}