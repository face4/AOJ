#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int key, pri;
    Node* left;
    Node* right;
};

Node* _del(Node* t, int key);

Node* newNode(int k, int p){
    Node* ret = (Node*)(malloc(sizeof(Node)));
    ret->key = k;
    ret->pri = p;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

Node* rightRotate(Node* t){
    Node* s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

Node* leftRotate(Node* t){
    Node* s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

Node* insert(Node* t, int key, int pri){
    if(t == NULL){
        return newNode(key, pri);
    }
    if(key == t->key){
        return t;
    }
    if(key < t->key){
        t->left = insert(t->left, key, pri);
        if(t->pri < t->left->pri)   t = rightRotate(t);
    }else{
        t->right = insert(t->right, key, pri);
        if(t->pri < t->right->pri)   t = leftRotate(t);
    }
    return t;
}

// 削除対象となるNodeを検索
Node* del(Node* t, int key){
    if(t == NULL){
        return NULL;
    }
    if(key < t->key){
        t->left = del(t->left, key);
    }else if(key > t->key){
        t->right = del(t->right, key);
    }else{
        return _del(t, key);
    }
    return t;
}

// 削除対象の節点
Node* _del(Node* t, int key){
    if(t->left == NULL && t->right == NULL){
        return NULL;
    }else if(t->left == NULL){
        t = leftRotate(t);
    }else if(t->right == NULL){
        t = rightRotate(t);
    }else{
        if(t->left->pri < t->right->pri){
            t = leftRotate(t);
        }else{
            t = rightRotate(t);
        }
    }
    return del(t, key);
}

void in(Node* t){
    if(t->left != NULL) in(t->left);
    cout << " " << t->key;
    if(t->right != NULL) in(t->right);
}

void pre(Node* t){
    cout << " " << t->key;
    if(t->left != NULL) pre(t->left);
    if(t->right != NULL) pre(t->right);
}

bool find(Node* t, int key){
    if(t == NULL)   return false;
    if(t->key == key)   return true;
    if(key < t->key)    return find(t->left, key);
    else                return find(t->right, key);
}

int main(){
    Node* root = NULL;
    int m;
    cin >> m;
    while(m-- > 0){
        string s;
        cin >> s;
        if(s == "insert"){
            int key, pri;
            cin >> key >> pri;
            root = insert(root, key, pri);
        }else if(s == "print"){
            in(root);   cout << endl;
            pre(root);  cout << endl;
        }else if(s == "delete"){
            int key;    cin >> key;
            root = del(root, key);
        }else if(s == "find"){
            int key;    cin >> key;
            cout << (find(root, key) ? "yes" : "no") << endl;
        }
    }
    return 0;
}