#include<iostream>
#include<vector>
using namespace std;

vector<int> par[1000];
string s[1000];

void dfs(int depth, int j){
    for(int i = 0; i < depth; i++)  cout << ".";
    cout << s[j] << endl;

    for(int i = 0; i < par[j].size(); i++){
        dfs(depth+1, par[j][i]);
    }
}

int main(){
    int n;
    cin >> n;

    int k;
    
    cin >> k >> s[0];

    if(n == 1){
        cout << s[0] << endl;
        return 0;
    }

    for(int i = 1; i < n; i++){
        cin >> k >> s[i];
        par[--k].push_back(i);
    }

    dfs(0, 0);

    return 0;
}