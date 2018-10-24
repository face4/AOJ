#include<iostream>
using namespace std;

bool used[26];
int d[26][26];

void dfs(int from){
    used[from] = true;
    for(int j = 0; j < 26; j++){
        if(d[from][j] && !used[j])  dfs(j);
    }
}

int main(){
    int n;
    while(cin >> n, n){
        for(int i = 0; i < 26; i++) used[i] = false;
        for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) d[i][j] = 0;

        bool avail[26] = {};
        string w;

        for(int i = 0; i < n; i++){
            cin >> w;
            avail[w[0]-'a'] = avail[w[w.length()-1]] = true;
            if(w[0] == w[w.length()-1]) continue;
            d[w[0]-'a'][w[w.length()-1]-'a']++;
        }

        bool euler = true;
        for(int i = 0; i < 26; i++){
            int indeg = 0, outdeg = 0;
            for(int j = 0; j < 26; j++){
                indeg += d[i][j];
                outdeg += d[j][i];
            }
            if(indeg != outdeg) euler = false;
        }

        if(euler){
            dfs(w[0]-'a');
            for(int i = 0; i < 26; i++) if(avail[i] && !used[i])    euler = false;
        }

        if(euler)   cout << "OK" << endl;
        else        cout << "NG" << endl;
    }
    return 0;
}