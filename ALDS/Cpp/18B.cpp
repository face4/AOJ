#include<iostream>
using namespace std;

struct Node{
    int key;
    Node *right, *parent, *left;
};

Node *root;
Node *NIL;

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
        }
    }

    return 0;
}