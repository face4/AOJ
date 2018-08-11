
/**
 * 0036 A Figure on Surface
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] figure = new String[8];
        int[] pos = new int[8];

        String input;

        while ((input = br.readLine()) != null) {
            for (int i = 0; i < 8; i++) {
                pos[i] = 0;
            }

            int counter = 0;

            figure[0] = input;
            if ((pos[0] = input.indexOf("1")) != -1) {
                counter++;
            }

            for (int i = 1; i < 8; i++) {
                input = br.readLine();
                figure[i] = input;

                if ((pos[i] = input.indexOf("1")) != -1) {
                    counter++;
                }
            }
            br.readLine(); // 空行処理

            String result = "";
            int forward = 0; // 探査用

            switch (counter) {
            case 1:
                result = "C";
                break;
            case 4:
                result = "B";
                break;
            case 2:
                forward = 0;
                while (pos[forward] == -1) {
                    forward++;
                }
                if (pos[forward] == pos[forward + 1]) {
                    result = "A";
                    break;
                } else if (pos[forward] < pos[forward + 1]) {
                    result = "E";
                    break;
                } else if (pos[forward] > pos[forward + 1]) {
                    result = "G";
                    break;
                }
                break; // unreachable
            case 3:
                forward = 0;
                while (pos[forward] == -1) {
                    forward++;
                }
                if(pos[forward] == pos[forward+1]){
                    result = "F";
                    break;
                }else if(pos[forward] > pos[forward+1]){
                    result = "D";
                    break;
                }
                break; // unreachable
            }

            System.out.println(result);
        }
    }
}