#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<string> con, res;
int score, t;
string s;
map<int,int> m;

void dfs(int cur){
    if(cur == s.length()){
        int tmp = 0;
        for(string x : con) tmp += stoi(x);
        if(tmp <= t && tmp >= score){
            score = tmp;
            res = con;
            m[tmp]++;
        }
        return;
    }

    for(int k = cur+1; k <= s.length(); k++){
        con.push_back(s.substr(cur, k-cur));
        dfs(k);
        con.pop_back();
    }
}

int main(){
    while(cin >> t >> s, t != 0 && s != "0"){
        m.clear();
        con.clear();
        score = -1;
        int tmp = 0;
        for(char c : s)   tmp += c-'0';
        if(t < tmp){
            cout << "error" << endl;
            continue;
        }
        dfs(0);
        if(m[score] != 1){
            cout << "rejected" << endl;
        }else{
            cout << score << " ";
            for(int i = 0; i < res.size(); i++)    cout << res[i] << " \n"[i+1==res.size()];
        } 
    }
    return 0;
}