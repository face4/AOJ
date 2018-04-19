
/**
 * ALDS1_7_B Tree - Binary Trees
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Node {
    int number;
    Node parent;
    Node sibling;
    int degree;
    Node left;
    Node right;
    int depth;
    int height;
    String type;

    Node(int number) {
        this.number = number;
        this.parent = null;
        this.sibling = null;
        this.degree = 0;
        this.type = "new";
    }

    void setLeft(Node left) {
        this.left = left;
        left.parent = this;
        this.degree++;
    }

    void setRight(Node right) {
        this.right = right;
        right.parent = this;
        this.degree++;
    }

    void setDepth(int depth) {
        this.depth = depth;
        if (this.left != null)
            this.left.setDepth(depth + 1);
        if (this.right != null)
            this.right.setDepth(depth + 1);
    }

    int getHeight(int height) {
        if (this.degree == 0) {
            return height;
        } else if (this.degree == 1) {
            if (this.left == null) {
                return this.right.getHeight(height + 1);
            } else {
                return this.left.getHeight(height + 1);
            }
        } else if (this.degree == 2) {
            return Math.max(this.left.getHeight(height + 1), this.right.getHeight(height + 1));
        }

        return 0; //unreachable
    }

    void setSibling() {
        if (this.left != null) {
            if (this.right != null) {
                this.left.sibling = this.right;
                this.right.sibling = this.left;
                this.right.setSibling();
            }
            this.left.setSibling();
        } else {
            if (this.right != null) {
                this.right.setSibling();
            } else {
                // do nothing.
            }
        }
    }

}

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Node[] bintree = new Node[n];
        Node root;

        // initialize
        for (int i = 0; i < n; i++) {
            bintree[i] = new Node(i);
        }

        // data input
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");

            int num = Integer.parseInt(input[0]);
            int leftNum = Integer.parseInt(input[1]);
            int rightNum = Integer.parseInt(input[2]);

            // set type and children
            if (leftNum + rightNum == -2) {
                bintree[num].type = "leaf";
            } else {
                bintree[num].type = "internal node";
                if (leftNum == -1) {
                    bintree[num].setRight(bintree[rightNum]);
                } else if (rightNum == -1) {
                    bintree[num].setLeft(bintree[leftNum]);
                } else {
                    bintree[num].setRight(bintree[rightNum]);
                    bintree[num].setLeft(bintree[leftNum]);
                }
            }
        }

        // set root
        root = bintree[0];
        while (root.parent != null) {
            root = root.parent;
        }
        root.type = "root";

        // set depth
        root.setDepth(0);

        // set height
        for (int i = 0; i < n; i++) {
            bintree[i].height = bintree[i].getHeight(0); // よくわからない実装 
        }

        // set sibling
        root.setSibling();

        // display
        String format = "node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s%n";

        for (int i = 0; i < n; i++) {
            if (bintree[i].type.equals("root")) {
                System.out.printf(format, i, -1, -1, bintree[i].degree, bintree[i].depth, bintree[i].height, "root");
            } else if (bintree[i].sibling == null) {
                System.out.printf(format, i, bintree[i].parent.number, -1, bintree[i].degree, bintree[i].depth,
                        bintree[i].height, bintree[i].type);
            } else {
                System.out.printf(format, i, bintree[i].parent.number, bintree[i].sibling.number, bintree[i].degree,
                        bintree[i].depth, bintree[i].height, bintree[i].type);
            }
        }
    }
}