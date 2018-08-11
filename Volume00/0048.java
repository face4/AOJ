
/**
 * 0048 Class
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static String classify(double w) {
        if (w <= 48.00)
            return "light fly";
        else if (w <= 51.00)
            return "fly";
        else if (w <= 54.00)
            return "bantam";
        else if (w <= 57.00)
            return "feather";
        else if (w <= 60.00)
            return "light";
        else if (w <= 64.00)
            return "light welter";
        else if (w <= 69.00)
            return "welter";
        else if (w <= 75.00)
            return "light middle";
        else if (w <= 81.00)
            return "middle";
        else if (w <= 91.00)
            return "light heavy";
        else
            return "heavy";
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;
        while ((line = br.readLine()) != null) {
            System.out.println(classify(Double.parseDouble(line)));
        }

    }
}