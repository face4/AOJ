#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int> v, int before, int res){
    if(res == 0){
        for(int i = 0; i < v.size(); i++){
            if(i)   cout << " ";
            cout << v[i];
        }
        cout << endl;
        return;
    }

    for(int j = res; j >= 1; j--){
        if(before >= j){
            v.push_back(j);
            dfs(v, j, res-j);
            v.pop_back();
        }
    }
}

int main(){
    int n;
    while(cin >> n, n){
        for(int j = n; j >= 1; j--){
            vector<int> v;
            v.push_back(j);
            dfs(v, j, n-j);
        }
    }
    return 0;
}