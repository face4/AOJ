#include<iostream>
#include<vector>
using namespace std;

int arr[6][3] = {
    {0, 1, 2}, 
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};

vector<int> w(6, 0);
bool valid = false;

void dfs(vector<int> v){
    if(v[0] == 0 && v[1] == 1 && v[2] == 2){
        valid = true;
        return;
    }
    for(int i = 0; i < 6; i++){
        if(w[i] == 0)   continue;
        w[i]--;
        vector<int> next(3);
        for(int j = 0; j < 3; j++)  next[j] = v[arr[i][j]];
        dfs(next);
        w[i]++;
    }
}

int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        vector<int> v({0, 1, 2});
        int q;  cin >> q;
        while(q-- > 0){
            int a;  cin >> a;
            if(a == 0)  swap(v[0], v[1]);
            if(a == 1)  swap(v[1], v[2]);
        }
        for(int i = 0; i < 6; i++){
            bool valid = true;
            for(int j = 0; j < 3; j++){
                valid &= arr[i][j]==v[j];
            }
            if(valid)   w[i]++;
        }
    }
    if(w[0] >= 1 || w[1] >= 2 || w[2] >= 2 || w[3] >= 3 || w[4] >= 3 || w[5] >= 2){
        valid = true;
    }else{
        for(int i = 0; i < 6; i++){
            if(w[i] == 0)   continue;
            vector<int> next(3);
            for(int j = 0; j < 3; j++)  next[j] = arr[i][j];
            w[i]--;
            dfs(next);
            w[i]++;
        }
    }
    cout << (valid ? "yes" : "no") << endl;
    return 0;
}