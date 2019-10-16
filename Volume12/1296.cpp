#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

bool startsWith(string str, int off, string pre){
    int s = str.length(), p = pre.length();
    if(off+p > s)   return false;

    int j;
    for(j = 0; j < p; j++){ 
        if(str[off+j] != pre[j])  break;
    }

    return j == p;
}

int main(){
    int n;
    while(cin >> n, n){
        string a[n], b[n];
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
        }
        string s, t;
        cin >> s >> t;
        set<string> made;
        queue<pair<string,int>> q;
        q.push({s,0});
        int ans = -1;
        while(!q.empty()){
            pair<string,int> p = q.front(); q.pop();
            string x = p.first;
            if(x == t){
                ans = p.second;
                break;
            }
            for(int i = 0; i < n; i++){
                string tmp = "";
                for(int j = 0; j < x.length(); j++){
                    if(startsWith(x, j, a[i]))  tmp += b[i], j += a[i].length()-1;
                    else                        tmp += x[j];
                }
                if(tmp.length() > t.length() || made.count(tmp))    continue;
                made.insert(tmp);
                q.push({tmp, p.second+1});
            }
        }
        cout << ans << endl;
    }
    return 0;
}