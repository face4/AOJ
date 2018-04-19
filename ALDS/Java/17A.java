
/**
 * ALDS1_7_A Tree - Rooted Trees
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Node {
    Node parent;
    Node[] child;

    int number;
    String type;
    int depth;

    Node(int number) {
        this.number = number;
        this.parent = null;
        this.type = "new";
    }

    void setDepth(int dep) {
        this.depth = dep;
        if (!this.type.equals("leaf")) {
            for (Node x : this.child) {
                x.setDepth(dep + 1);
            }
        }
    }

}

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Node[] tree = new Node[n];

        for (int i = 0; i < n; i++) {
            tree[i] = new Node(i);
        }

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");

            int number = Integer.parseInt(input[0]);
            int k = Integer.parseInt(input[1]);
            if (k == 0) {
                tree[number].type = "leaf";
                continue;
            } else {
                tree[number].child = new Node[k];
                tree[number].type = "internal node"; // rootのみ後で上書き
            }

            for (int j = 0; j < k; j++) {
                tree[number].child[j] = tree[Integer.parseInt(input[2 + j])];
                tree[Integer.parseInt(input[2 + j])].parent = tree[number];
            }

        }

        Node root = tree[0];

        // find root;
        while (root.parent != null) {
            root = root.parent;
        }

        root.type = "root";

        // set depth;
        if(n != 1) root.setDepth(0);
        int rootNum = root.number;

        // display
        String format = "node %d: parent = %d, depth = %d, %s, ";
        for (int i = 0; i < n; i++) {
            if (i != rootNum) {
                System.out.printf(format, i, tree[i].parent.number, tree[i].depth, tree[i].type);
            } else {
                System.out.printf(format, i, -1, tree[i].depth, tree[i].type);
            }

            System.out.print("[");
            if(n != 1){
                if (!tree[i].type.equals("leaf")) {
                    int j;
                    for (j = 0; j < tree[i].child.length - 1; j++) {
                        System.out.printf(tree[i].child[j].number + ", ");
                    }
                    System.out.print(tree[i].child[j].number);
                }
            }
            System.out.println("]");
        }

    }
}