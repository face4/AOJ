#include<iostream>
#include<map>
using namespace std;

int main(){
    int h, w;
    while(cin >> h >> w, h+w){
        map<char, pair<int,int>> m;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                char c; cin >> c;
                if(c == '_')    continue;
                m[c] = {i,j};
            }
        }
        string s;
        cin >> s;
        int i = 0, j = 0, ans = s.length();
        for(char c : s) ans += abs(m[c].first-i)+abs(m[c].second-j), i = m[c].first, j = m[c].second;
        cout << ans << endl;
    }
    return 0;
}