
/**
 * 0015-National Budget
 */
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            StringBuilder sb1 = new StringBuilder();
            StringBuilder sb2 = new StringBuilder();
            String[] result = new String[10];
            int pos = 9; // 結果を順次格納していく、indexの把握

            String first = br.readLine();
            String second = br.readLine();

            if (first.length() > 80 || second.length() > 80) {
                System.out.println("overflow");
                continue;
            }

            for (int j = 0; j < 80 - first.length(); j++) {
                sb1.append("0");
            }
            sb1.append(first);

            for (int j = 0; j < 80 - second.length(); j++) {
                sb2.append("0");
            }
            sb2.append(second);

            // System.out.println("sb1 : " + sb1.toString());
            // System.out.println("sb2 : " + sb2.toString());

            int carry = 0;
            for (int j = 0; j < 10; j++) {
                int x = Integer.parseInt(sb1.toString().substring(sb1.length() - 8, sb1.length()));
                int y = Integer.parseInt(sb2.toString().substring(sb2.length() - 8, sb2.length()));

                sb1.delete(sb1.length() - 8, sb1.length());
                sb2.delete(sb2.length() - 8, sb2.length());

                String value = String.valueOf(x + y + carry);
                if (value.length() > 8) {
                    value = value.substring(1);
                }
                StringBuilder tmp = new StringBuilder();
                for (int k = 0; k < 8 - value.length(); k++) {
                    tmp.append("0");
                }
                tmp.append(value);
                result[pos] = tmp.toString();
                pos--;
                carry = (x + y + carry) / 100000000;
            }

            // display
            if (carry != 0) {
                System.out.println("overflow");
            } else {
                String x = "";
                for (String y : result)
                    x = x + y;
                int index = -1;
                while (index < 79 && x.charAt(++index) == '0');
                System.out.println(x.substring(index));
            }

        }
    }
}