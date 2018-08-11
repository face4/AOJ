// bfs
#include<iostream>
#include<set>
#include<queue>
using namespace std;

bool check(string a){
    char pivot = a[0];
    for(int i = 1; i < a.length(); i++) if(a[i] != pivot)   return false;
    return true;
}

char rgb[3] = {'r', 'g', 'b'};

int main(){
    string x;
    while(cin >> x){
        if(x == "0")    break;

        queue<pair<string,int>> q;
        set<string> s;

        q.push({x,0});

        int ans = -1;
        while(!q.empty()){
            pair<string,int> t = q.front(); q.pop();
            if(check(t.first)){
                ans = t.second;
                break;
            }
            
            if(s.find(t.first) != s.end())  continue;

            s.insert(t.first);
            for(int i = 0; i < t.first.length()-1; i++){
                if(t.first[i] == t.first[i+1])  continue;

                for(int j = 0; j < 3; j++){
                    if(t.first[i] != rgb[j] && t.first[i+1] != rgb[j]){
                        string copy = t.first;
                        copy.replace(i, 2, 2, rgb[j]);
                        if(s.find(copy) == s.end()) q.push({copy, t.second+1});
                    }
                }
            }
        }

        if(ans == -1)   cout << "NA" << endl;
        else            cout << ans << endl;
    }
    return 0;
}