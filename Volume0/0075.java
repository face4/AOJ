
/**
 * 0075 BMI
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            String[] input = line.split(",");
            double weight = Double.parseDouble(input[1]);
            double height = Double.parseDouble(input[2]);
            double bmi = weight / height / height;
            if (bmi >= 25) {
                System.out.println(input[0]);
            }
        }
    }
}