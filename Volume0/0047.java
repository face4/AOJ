
/**
 * 0047 Cup Game
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        HashMap<String, Boolean> map = new HashMap<String, Boolean>();
        map.put("A", true);
        map.put("B", false);
        map.put("C", false);

        String line;
        while ((line = br.readLine()) != null) {
            String[] input = line.split(",");
            if (map.get(input[0]) != map.get(input[1])) {
                map.put(input[0], !map.get(input[0]));
                map.put(input[1], !map.get(input[1]));
            }
        }

        for (String s : map.keySet()) {
            if (map.get(s)) {
                System.out.println(s);
                return;
            }
        }

    }
}