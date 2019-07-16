#include<iostream>
#include<vector>
using namespace std;

vector<int> cond(8,-1), ans(8);

bool valid(int pos){
    bool ret = true;
    for(int i = 0; i < pos; i++){
        ret &= ans[i] != ans[pos];
        ret &= abs(ans[pos]-ans[i]) != pos-i;
    }
    return ret;
}

void dfs(int pos){
    if(pos == 8){
        for(int i = 0; i < 8; i++){
            if(cond[i] != -1 && cond[i] != ans[i])  return;
        }
        // found!
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(ans[i] == j)    cout << "Q";
                else               cout << ".";
            }
            cout << endl;
        }
        exit(0);
    }
    for(int j = 0; j < 8; j++){
        ans[pos] = j;
        if(!valid(pos))  continue;
        dfs(pos+1);
    }
}

int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        int i, j;
        cin >> i >> j;
        cond[i] = j;
    }
    dfs(0);
    return 0;
}