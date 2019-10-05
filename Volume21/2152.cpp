#include<iostream>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    int n;
    while(cin >> n, n){
        set<pair<int,pair<int,int>>> s;
        for(int i = 0; i < n; i++){
            char c; cin >> c;
            if(c == 'W'){
                int id, t;
                cin >> id >> t;
                auto it = s.begin();
                int next = 0;
                while(t > 0){
                    if(it == s.end()){
                        s.insert({next, {id, t}});
                        break;
                    }
                    if(next < it->first){
                        s.insert({next, {id, min(it->first-next, t)}});
                        t -= min(it->first-next, t);
                    }
                    next = it->first + it->second.second;
                    it++;
                }
            }else if(c == 'D'){
                int id;
                cin >> id;
                auto it = s.begin();
                while(it != s.end()){
                    if(it->second.first == id) it = s.erase(it);
                    else                       it++;
                }
            }else if(c == 'R'){
                int pos;
                cin >> pos;
                auto it = s.lower_bound({pos, {0, 0}});
                if(it != s.end() && it->first == pos){
                    cout << it->second.first << endl;
                }else if(it != s.begin()){
                    it--;
                    if(it->first+it->second.second > pos){
                        cout << it->second.first << endl;
                    }else{
                        cout << -1 << endl;
                    }
                }else{
                    cout << -1 << endl;
                }
            }
            // cout << "[" << i << "]" << endl;
            // for(auto p : s) cout << "(" << p.first << "," << p.second.first << " " << p.second.second << ") ";
            // cout << endl;
        }
        cout << endl;
    }
    return 0;
}