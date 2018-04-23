
/**
 * 0123 Speed Skating Badge Test
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static String classify(double a, double b) {
        if (a < 35.5 && b < 71) {
            return "AAA";
        } else if (a < 37.5 && b < 77) {
            return "AA";
        } else if (a < 40 && b < 83) {
            return "A";
        } else if (a < 43 && b < 89) {
            return "B";
        } else if (a < 50 && b < 105) {
            return "C";
        } else if (a < 55 && b < 116) {
            return "D";
        } else if (a < 70 && b < 148) {
            return "E";
        } else {
            return "NA";
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            String[] input = line.split(" ");
            double a = Double.parseDouble(input[0]);
            double b = Double.parseDouble(input[1]);
            System.out.println(classify(a, b));
        }
    }
}