#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    map<string,int> cnt;
    vector<string> v;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        cnt[s]++;
        v.push_back(s);
    }
    vector<string> rev = v;
    for(string &s : rev)    reverse(s.begin(),s.end());

    sort(v.begin(), v.end());
    sort(rev.begin(), rev.end());

    auto f = [](string s, vector<string> &v)->int{
        vector<string>::iterator l = lower_bound(v.begin(),v.end(),s);
        s.back() = s.back()+1;
        vector<string>::iterator r = lower_bound(v.begin(),v.end(),s);
        return r-l;
    };

    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        int flag = 0;
        if(s[0]=='*')           flag = 2, s = s.substr(1), reverse(s.begin(),s.end());
        else if(s.back()=='*')  flag = 1, s = s.substr(0,s.length()-1);
        int ind = -1;
        for(int j = 0; j < s.length(); j++) if(s[j] == '?') ind = j;
        int ans = 0;
        if(flag == 0){
            if(ind == -1)   ans = cnt[s];
            else            for(char c = 'a'; c <= 'z'; c++)    s[ind]=c, ans += cnt[s];
        }else if(flag == 1){
            if(ind == -1)   ans = f(s, v);
            else            for(char c = 'a'; c <= 'z'; c++)    s[ind]=c, ans += f(s, v);
        }else if(flag == 2){
            if(ind == -1)   ans = f(s, rev);
            else            for(char c = 'a'; c <= 'z'; c++)    s[ind]=c, ans += f(s, rev);
        }
        cout << ans << endl;
    }
    return 0;
}