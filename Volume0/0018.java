/**
 * 0018-Sorting Five Numbers
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ", 5);
        int[] data = new int[5];

        for (int i = 0; i < 5; i++) {
            data[i] = Integer.parseInt(input[i]);
        }

        for (int j = 0; j < 4; j++) {
            for (int i = 4; i > j; i--) {
                if (data[i - 1] < data[i]) {
                    int swp = data[i];
                    data[i] = data[i - 1];
                    data[i - 1] = swp;
                }
            }
        }
        StringBuilder sb = new StringBuilder();

        for (int i : data) {
            sb.append(i);
            sb.append(" ");
        }

        System.out.println(sb.substring(0 , sb.length()-1));
    }
}