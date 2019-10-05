#include<iostream>
#include<cctype>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int val;
};

Node* newNode(int x){
    Node* cur = (Node*)malloc(sizeof(Node));
    cur->val = x;
    cur->left = NULL;
    cur->right = NULL;
    return cur;
}

void print(Node* x){
    cout << "(";
    if(x->left != NULL)     print(x->left);
    cout << ")[" << x->val << "](";
    if(x->right != NULL)    print(x->right);
    cout << ")";
}

Node* dfs(int &pos, const string &s){
    if(s[pos] != '('){
        return NULL;
    }
    pos++;  // (
    Node* root = newNode(-1);
    root->left = dfs(pos, s);
    pos++;  // )
    pos++;  // [
    int num = 0;
    while(isdigit(s[pos])){
        num = num*10 + s[pos++]-'0';
    }
    root->val = num;
    pos++;  // ]
    pos++;  // (
    root->right = dfs(pos, s);
    pos++;  // )
    return root;
}

Node* unite(Node* l, Node* r){
    if(l == NULL || r == NULL)  return NULL;
    Node* root = newNode(l->val + r->val);
    root->left = unite(l->left, r->left);
    root->right = unite(l->right, r->right);
    return root;
}

int main(){
    string a, b;
    cin >> a >> b;

    int pos = 0;
    Node* roota = dfs(pos, a);
    pos = 0;
    Node* rootb = dfs(pos, b);

    Node* ret = unite(roota, rootb);

    print(ret);
    cout << endl;

    return 0;
}