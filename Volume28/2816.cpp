#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int cnt[26] = {};
    for(int i = 0; i < s.length(); i++){
        cnt[s[i]-'a']++;
        if(cnt[s[i]-'a'] == 2)  cnt[s[i]-'a'] = 0;
    }

    int alone = 0;
    for(int i = 0; i < 26; i++) alone += cnt[i];

    cout << alone/2 << endl;

    return 0;
}