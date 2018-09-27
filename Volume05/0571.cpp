#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<pair<char,int>> m;
    string s;
    cin >> s;

    char x = s[0];
    int cnt = 1;
    for(int i = 1; i < s.length(); i++){
        if(x == s[i]){
            cnt++;
        }else{
            m.push_back({x, cnt});
            x = s[i];
            cnt = 1;
        }
    }
    m.push_back({x, cnt});

    int n = m.size();
    int ans = 0;

    for(int i = 0; i < n-2; i++){
        if(m[i].first == 'J' && m[i+1].first == 'O' && m[i+2].first == 'I'){
            if(m[i].second >= m[i+1].second && m[i+2].second >= m[i+1].second)
                ans = max(ans, m[i+1].second);
        }
    }

    cout << ans << endl;

    return 0;
}