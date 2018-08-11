
/**
 * 0065 Trading
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
        ArrayList<Integer> cont = new ArrayList<Integer>();
        HashMap<Integer, Integer> times = new HashMap<Integer, Integer>();
        // 意地悪で全く同じデータがある場合、arraylist<string>で重複を管理する必要あり

        String line;
        while (!(line = br.readLine()).equals("")) {
            String[] input = line.split(",");
            int company = Integer.parseInt(input[0]);
            // int day = Integer.parseInt(input[1]);

            if (!cont.contains(company)) {
                cont.add(company);
            }

            if (times.containsKey(company)) {
                times.put(company, times.get(company) + 1);
            } else {
                times.put(company, 1);
            }
        }

        ArrayList<Integer> ok = new ArrayList<Integer>();

        while ((line = br.readLine()) != null) {
            String[] input = line.split(",");
            int company = Integer.parseInt(input[0]);
            // int day = Integer.parseInt(input[1]);

            if (cont.contains(company)) {
                if (!ok.contains(company))
                    ok.add(company);
            }

            if (times.containsKey(company)) {
                times.put(company, times.get(company) + 1);
            }
        }

        Object[] companiesO = ok.toArray();
        int[] companies = new int[companiesO.length];
        for (int i = 0; i < companies.length; i++) {
            companies[i] = (int) companiesO[i];
        }
        Arrays.sort(companies);

        for (int i = 0; i < companies.length; i++) {
            System.out.println(companies[i] + " " + times.get(companies[i]));
        }
    }
}