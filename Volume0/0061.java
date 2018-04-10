
/**
 * 0061 Rank Checker
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Integer, Integer> data = new HashMap<Integer, Integer>();
        ArrayList<Integer> scores = new ArrayList<Integer>();

        String line;
        while (!(line = br.readLine()).equals("0,0")) {
            String[] input = line.split(",");
            int p = Integer.parseInt(input[0]);
            int s = Integer.parseInt(input[1]);
            data.put(p, s);
            if (!scores.contains(s)) {
                scores.add(s);
            }
        }

        Object[] o = scores.toArray();
        int length = o.length;
        int[] score = new int[length];
        for (int i = 0; i < length; i++) {
            score[i] = (int) o[i];
        }

        Arrays.sort(score);

        while ((line = br.readLine()) != null) {
            int n = Integer.parseInt(line);
            int point = data.get(n);

            // 順位を探す
            int i = -1;
            while (point != score[++i])
                ;

            System.out.println((length - i));
        }

    }
}