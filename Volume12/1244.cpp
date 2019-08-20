#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int win[26] = {};

struct node{
    int id;
    node *left;
    node *right;
    node (int i){
        id = i;
        left = NULL;
        right = NULL;
    }
};

node* new_node(int id){
    node *ret;
    ret = (node*)malloc(sizeof(node));
    ret->id = id;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

string s;

node* f(int &pos){
    if(inRange(s[pos], 'a', 'z')){
        return new_node(s[pos++]-'a');
    }
    if(s[pos] == '['){
        pos++;
        node* ret = new_node(-1);
        ret->left = f(pos);
        pos++;  // -
        ret->right = f(pos);
        pos++;  // ]
        return ret;
    }
    return NULL;    // unreachable
}

bool valid = true;

int dfs(node *cur){
    if(cur->id != -1){
        return cur->id;
    }else{
        int a = dfs(cur->left);
        int b = dfs(cur->right);
        int judge = (win[a]!=0) + (win[b]!=0);
        if(judge == 0 || judge == 2){
            valid = false;
        }
        if(win[a] == 0){
            win[b]--;
            return b;
        }else if(win[b] == 0){
            win[a]--;
            return a;
        }else{
            // invalid
            return 0;
        }
    }
}

int main(){
    cin >> s;
    char c; int x;
    while(cin >> c >> x){
        win[c-'a'] = x;
    }
    int pos = 0;
    node *root = f(pos);
    cout << (win[dfs(root)] == 0 && valid ? "Yes" : "No") << endl;
    return 0;
}
