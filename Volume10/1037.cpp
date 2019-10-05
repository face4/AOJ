#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> op, sweet;
int k;

struct Node{
    Node* left;
    Node* right;
    int id;
    int bit;
};

Node* newNode(){
    Node* ret = (Node*)(malloc(sizeof(Node)));
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

Node* build(int &pos, string s){
    Node* ret = newNode();
    if(s[pos] == '('){
        ret->id = k++;
        pos++;
        ret->left = build(pos, s);
        pos++;  // space
        ret->right = build(pos, s);
        pos++;  // )
    }else{
        int num = s[pos++]-'0';
        ret->bit = sweet[num-1];
    }
    return ret;
}

int play(Node* root){
    if(root->left != NULL){
        int x = play(root->left), y = play(root->right);
        if(op[root->id] == 0)   root->bit = x&y;
        if(op[root->id] == 1)   root->bit = x|y;
        if(op[root->id] == 2)   root->bit = x^y;
    }
    return root->bit;
}

int main(){
    string s;
    while(getline(cin, s), s != "END"){
        int n;
        cin >> n;
        k = 0;
        sweet.clear();
        for(int i = 0; i < n; i++){
            int bit = 0;
            for(int j = 0; j < 4; j++){
                int x;  cin >> x;
                bit += x * (1<<j);
            }
            sweet.push_back(bit);
        }
        int pos = 0;
        Node* root = build(pos, s);
        op.assign(k, 0);
        int ans = 0;
        for(int i = 0; i < pow(3,k); i++){
            int cp = i;
            for(int j = 0; j < k; j++){
                op[j] = cp%3;
                cp /= 3;
            }
            if(play(root) == (1<<4)-1)  ans++;
        }
        cout << ans << endl;
        cin.ignore();
    }
    return 0;
}