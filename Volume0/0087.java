
/**
 * 0087 Strange Mathematical Expression
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class MyStack {
    // s[0] は常に空
    int size = 81;
    String[] s;
    int top;

    MyStack() {
        s = new String[size];
        top = 0;
    }

    void push(String str) {
        s[++top] = str;
    }

    String pop() {
        return s[top--];
    }

    double eval() {
        String x = pop();
        if (isNumber(x)) {
            return Integer.parseInt(x);
        }

        double a = eval();
        double b = eval();

        switch (x) {
        case "+":
            return a + b;
        case "-":
            return b - a;
        case "*":
            return a * b;
        case "/":
            return b / a;
        }
        return 0;
    }

    boolean isNumber(String x) {
        try {
            Integer.parseInt(x);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
}

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            MyStack ms = new MyStack();
            String[] input = line.split(" ");
            for (String s : input) {
                ms.push(s);
            }

            while (ms.top != 1) {
                ms.push(String.valueOf(ms.eval()));
            }

            System.out.printf("%.6f%n", Double.parseDouble(ms.pop()));
        }

    }
}