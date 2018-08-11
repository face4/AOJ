
/**
 * 0101 Sale Result
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.ArrayList;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;
        while (!(line = br.readLine()).equals("0")) {
            HashMap<Integer, Long> map = new HashMap<Integer, Long>();
            ArrayList<Integer> shine = new ArrayList<Integer>();
            int n = Integer.parseInt(line);
            for (int i = 0; i < n; i++) {
                String[] input = br.readLine().split(" ");
                int e = Integer.parseInt(input[0]);
                if (!shine.contains(e))
                    shine.add(e);
                long p = Long.parseLong(input[1]);
                long q = Long.parseLong(input[2]);

                if (map.containsKey(e)) {
                    if (map.get(e) == Long.MAX_VALUE) {
                        continue;
                    }
                    if (p * q + map.get(e) >= 1000000) {
                        map.put(e, Long.MAX_VALUE);
                    } else {
                        map.put(e, p * q + map.get(e));
                    }
                } else {
                    if (p * q >= 1000000) {
                        map.put(e, Long.MAX_VALUE);
                    } else {
                        map.put(e, p * q);
                    }
                }
            }

            boolean isNA = true;
            for (Object x : shine.toArray()) {
                int e = (int) x;
                if (map.get(e) == Long.MAX_VALUE) {
                    System.out.println(e);
                    isNA = false;
                }
            }

            if (isNA)
                System.out.println("NA");
        }
    }
}