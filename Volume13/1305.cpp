#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

map<string, int> check;
map<string, set<string>> mem;

void dfs(string s){
    if(check.count(s))    return;

    vector<string> groups;
    for(string member : mem[s]){
        if(mem.count(member)){
            dfs(member);
            groups.push_back(member);
        }
    }

    for(string member : groups){
        mem[s].erase(member);
        mem[s].insert(mem[member].begin(), mem[member].end());
    }

    check[s] = 1;
    return;
}

int main(){
    int n;
    while(cin >> n, n){
        string first = "";
        while(n-- > 0){
            string s;
            cin >> s;
            int cur = 0;
            while(s[cur] != ':')    cur++;
            string name = s.substr(0, cur);
            if(first == "") first = name;
            cur++;
            while(cur < s.length()){
                int next = cur;
                while(s[next] != '.' && s[next] != ',') next++;
                mem[name].insert(s.substr(cur, next-cur));
                cur = next+1;
            }
        }
        dfs(first);
        cout << mem[first].size() << endl;
        mem.clear();
        check.clear();
    }
    return 0;
}