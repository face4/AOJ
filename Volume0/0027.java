
/**
 * 0027 What day is today?
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        //処理の関係で添え字0は使わない(0-originだとコードの可読性が下がる)
        int[] days = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        String[] answer = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

        String input;
        while ((input = br.readLine()) != null) {
            String[] line = input.split(" ");
            
            if(line[0].equals("0")) break;

            int month = Integer.parseInt(line[0]);
            int day = Integer.parseInt(line[1]);

            for (int i = 1; i < month; i++) {
                day += days[i];
            }

            System.out.println(answer[(day + 2) % 7]);

        }
    }
}