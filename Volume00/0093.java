
/**
 * 0093 Leap Year
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;
        boolean first = true;

        while (!(line = br.readLine()).equals("0 0")) {
            if(!first)  System.out.println();
            String[] input = line.split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            StringBuilder sb = new StringBuilder();

            boolean isNA = true;

            for (int now = a; now <= b; now++) {
                if (now % 4 == 0) {
                    if(now % 100 == 0){
                        if(now % 400 == 0){
                            sb.append(now).append("\n");
                            if (isNA)   isNA = false;
                        }
                    }else{
                        sb.append(now).append("\n");
                        if (isNA)   isNA = false;
                    }
                }
            }

            if (isNA) {
                sb.append("NA").append("\n");
            }

            System.out.print(sb);
            first = false;
        }

    }
}