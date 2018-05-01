#include<iostream>
using namespace std;

struct Node{
    int key;
    Node *right, *parent, *left;
};

Node *root;
Node *NIL;

Node* treeMinimum(Node *x){
    while(x->left != NIL){
        x = x->left;
    }
    return x;
}

Node* find(Node *u, int x){
    while(u != NIL && u->key != x){
        if(u->key < x){
            u = u->right;
        }else{
            u = u->left;
        }
    }
    return u;
}

Node* treeSuccessor(Node *x){
    if(x->right != NIL){
        return treeMinimum(x->right);
    }

    Node *y = x->parent;
    while(y != NIL && x == y->right){
        x = y;
        y = y->parent;
    }

    return y;
}

void treeDelete(Node *z){
    Node *y; // 削除対象のノード
    Node *x; // y の子

    if(z->left == NIL || z->right == NIL){
        y = z;
    }else{
        y = treeSuccessor(z);
    }

    if(y->left != NIL){
        x = y->left;  // x has a left child
    }else{
        x = y->right; // x has a right child, or no child
    }

    if(x != NIL){
        x->parent = y->parent;
    }

    if(y->parent == NIL){
        root = x;
    }else{
        if(y == y->parent->left){
            y->parent->left = x;
        }else{
            y->parent->right = x;
        }
    }

    if(y != z){
        z->key = y->key;
    }

    free(y);
}

void insert(int k){
    Node *y = NIL;
    Node *x = root; // 走査用
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while(x != NIL){
        y = x;
        if(x->key > z->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    z->parent = y;
    if(y == NIL){
        root = z;
    }else if(y->key > z->key){
        y->left = z;
    }else{
        y->right = z;
    }
}

void inorder(Node *u){
    if(u == NIL)    return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u){
    if(u == NIL)    return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main(){
    int n, i, x;
    string com;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        cin >> com;
        if(com == "insert"){
            scanf("%d", &x);
            insert(x);
        }else if(com == "print"){
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }else if(com == "find"){
            scanf("%d", &x);
            if(find(root, x) != NIL) printf("yes\n");
            else               printf("no\n");
        }else if(com == "delete"){
            scanf("%d", &x);
            treeDelete(find(root, x));
        }
    }

    return 0;
}