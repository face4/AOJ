#include<iostream>
using namespace std;

int main(){
    int ans = 0, cnt = 0;
    string s;
    cin >> s;
    for(char c : s){
        if(c == '(')    cnt++;
        else if(c == ')')   cnt--;
        else ans = cnt;
    }
    cout << ans << endl;
    return 0;
}