
/**
 * 0138 Track and Field Competition
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Collections;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Double, Integer> d1 = new HashMap<Double, Integer>();
        HashMap<Double, Integer> d2 = new HashMap<Double, Integer>();
        HashMap<Double, Integer> d3 = new HashMap<Double, Integer>();
        HashMap<Double, Integer> re = new HashMap<Double, Integer>();

        for (int i = 0; i < 8; i++) {
            String[] input = br.readLine().split(" ");
            d1.put(Double.parseDouble(input[1]), Integer.parseInt(input[0]));
        }
        for (int i = 0; i < 8; i++) {
            String[] input = br.readLine().split(" ");
            d2.put(Double.parseDouble(input[1]), Integer.parseInt(input[0]));
        }
        for (int i = 0; i < 8; i++) {
            String[] input = br.readLine().split(" ");
            d3.put(Double.parseDouble(input[1]), Integer.parseInt(input[0]));
        }

        ArrayList<Double> a1 = new ArrayList<Double>(d1.keySet());
        ArrayList<Double> a2 = new ArrayList<Double>(d2.keySet());
        ArrayList<Double> a3 = new ArrayList<Double>(d3.keySet());
        Collections.sort(a1);
        Collections.sort(a2);
        Collections.sort(a3);

        re.put(a1.get(2), d1.get(a1.get(2)));
        re.put(a1.get(3), d1.get(a1.get(3)));
        re.put(a2.get(2), d2.get(a2.get(2)));
        re.put(a2.get(3), d2.get(a2.get(3)));
        re.put(a3.get(2), d3.get(a3.get(2)));
        re.put(a3.get(3), d3.get(a3.get(3)));
        ArrayList<Double> r1 = new ArrayList<Double>(re.keySet());
        Collections.sort(r1);

        System.out.println(d1.get(a1.get(0)) + " " + a1.get(0));
        System.out.println(d1.get(a1.get(1)) + " " + a1.get(1));
        System.out.println(d2.get(a2.get(0)) + " " + a2.get(0));
        System.out.println(d2.get(a2.get(1)) + " " + a2.get(1));
        System.out.println(d3.get(a3.get(0)) + " " + a3.get(0));
        System.out.println(d3.get(a3.get(1)) + " " + a3.get(1));
        System.out.println(re.get(r1.get(0)) + " " + r1.get(0));
        System.out.println(re.get(r1.get(1)) + " " + r1.get(1));
    }
}