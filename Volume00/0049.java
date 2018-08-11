
/**
 * 0049 Blood Groups
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] blood = { 0, 0, 0, 0 };

        String line;
        while ((line = br.readLine()) != null) {
            String type = line.split(",")[1];
            switch (type) {
            case "A":
                blood[0]++;
                break;
            case "B":
                blood[1]++;
                break;
            case "AB":
                blood[2]++;
                break;
            case "O":
                blood[3]++;
                break;
            }
        }

        for(int i : blood){
            System.out.println(i);
        }
    }
}