/**
 * ALDS1_7_C Tree - Tree Walk
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Node{
    int number;
    Node left;
    Node right;
    Node parent;

    Node(int number){
        this.number = number;
        left = null;
        right = null;
        parent = null;
    }

    void preorder(){
        System.out.print(" " + this.number);
        if(this.left != null)   this.left.preorder();
        if(this.right != null)  this.right.preorder();
    }

    void inorder(){
        if(this.left != null)   this.left.inorder();
        System.out.print(" " + this.number);
        if(this.right != null)  this.right.inorder();
    }

    void postorder(){
        if(this.left != null)   this.left.postorder();
        if(this.right != null)  this.right.postorder();
        System.out.print(" " + this.number);
    }
}

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());

        Node[] tree = new Node[n];
        for(int i = 0; i < n; i++){
            tree[i] = new Node(i);
        }

        for(int i = 0; i < n; i++){
            String[] input = br.readLine().split(" ");
            int num = Integer.parseInt(input[0]);
            int left = Integer.parseInt(input[1]);
            int right = Integer.parseInt(input[2]);
            
            if(left+right != -2){
                if(left == -1){
                    tree[num].right = tree[right];
                    tree[right].parent = tree[num];
                }else if(right == -1){
                    tree[num].left = tree[left];
                    tree[left].parent = tree[num];
                }else{
                    tree[num].right = tree[right];
                    tree[num].left = tree[left];
                    tree[right].parent = tree[num];
                    tree[left].parent = tree[num];
                }
            }
        }

        Node root = tree[0];
        while(root.parent != null){
            root = root.parent;
        }

        System.out.println("Preorder");
        root.preorder();
        System.out.println("\nInorder");
        root.inorder();
        System.out.println("\nPostorder");
        root.postorder(); 
        System.out.println();     
    }
}