#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == '0') continue;
        int x = stoi(s.substr(0, i)), y = stoi(s.substr(i));
        if(x%2 == y%2){
            int a = (x+y)/2;
            if(a-x >= 0)    ans++;
        }
    }
    cout << ans+(s[s.length()-1]+1)%2 << endl;
    return 0;
}