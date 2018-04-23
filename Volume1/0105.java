
/**
 * 0105 Book Index
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, String> dict = new HashMap<String, String>();

        String line;
        while ((line = br.readLine()) != null) {
            String[] input = line.split(" ");
            if (dict.containsKey(input[0])) {
                dict.put(input[0], dict.get(input[0]) + " " + input[1]);
            } else {
                dict.put(input[0], input[1]);
            }
        }

        int length = dict.keySet().size();
        String[] keyset = new String[length];
        int index = 0;
        for (String s : dict.keySet()) {
            keyset[index++] = s;
        }

        Arrays.sort(keyset);

        for (int i = 0; i < length; i++) {
            System.out.println(keyset[i]);
            String[] pages = dict.get(keyset[i]).split(" ");
            int[] a = new int[pages.length];
            for (int j = 0; j < pages.length; j++) {
                a[j] = Integer.parseInt(pages[j]);
            }
            Arrays.sort(a);
            boolean isFirst = true;
            for (int j = 0; j < pages.length; j++) {
                if (isFirst) {
                    System.out.print(a[j]);
                    isFirst = false;
                } else {
                    System.out.print(" " + a[j]);
                }
            }
            System.out.println();
        }
    }
}