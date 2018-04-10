
/**
 * 0083 Era Name Transformation
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static String getEra(int ymd) {
        if (ymd < 18680908) {
            return "pre-meiji";
        } else if (ymd < 19120730) {
            return "meiji";
        } else if (ymd < 19261225) {
            return "taisho";
        } else if (ymd < 19890108) {
            return "showa";
        } else {
            return "heisei";
        }
    }

    static int getYear(String s, int y) {
        int base = 0;
        if (s.equals("meiji")) {
            base = 1868;
        } else if (s.equals("taisho")) {
            base = 1912;
        } else if (s.equals("showa")) {
            base = 1926;
        } else if (s.equals("heisei")) {
            base = 1989;
        }
        return y - base + 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            String[] input = line.split(" ");
            int year = Integer.parseInt(input[0]);
            int month = Integer.parseInt(input[1]);
            int day = Integer.parseInt(input[2]);

            StringBuilder value = new StringBuilder();
            value.append(year);
            if (month < 10)
                value.append(0);
            value.append(month);
            if (day < 10)
                value.append(0);
            value.append(day);

            String eraName = getEra(Integer.parseInt(value.toString()));

            if (eraName.equals("pre-meiji")) {
                System.out.println(eraName);
            } else {
                int yearX = getYear(eraName, year);
                System.out.printf("%s %d %d %d%n", eraName, yearX, month, day);
            }
        }
    }
}