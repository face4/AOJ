#include<iostream>
using namespace std;

struct Node{
    Node* left;
    Node* right;
};

Node* newNode(){
    Node* ret = (Node*)malloc(sizeof(Node));
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

Node* build(int &pos, const string s){
    if(s[pos] != '(')   return NULL;
    Node* ret = newNode();
    pos++;  // (
    ret->left = build(pos, s);
    pos++;  // ,
    ret->right = build(pos, s);
    pos++;  // )
    return ret;
}

void print(Node* root){
    cout << "(";
    if(root->left != NULL)  print(root->left);
    cout << ",";
    if(root->right != NULL) print(root->right);
    cout << ")";
}

Node* op(char c, Node* x, Node* y){
    int cnt = (x!=NULL) + (y!=NULL);
    if((cnt == 2 && c == 'i') || (cnt > 0 && c == 'u')){
        Node* root = newNode();
        root->left = op(c, (x==NULL ? NULL : x->left), (y==NULL ? NULL : y->left));
        root->right = op(c, (x==NULL ? NULL : x->right), (y==NULL ? NULL : y->right));
        return root;
    }else{
        return NULL;
    }
}

int main(){
    char c;
    string a, b;
    while(cin >> c >> a >> b){
        int pos = 0;
        Node* x = build(pos, a);
        pos = 0;
        Node* y = build(pos, b);
        print(op(c, x, y));
        cout << endl;
    }
    return 0;
}