#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[i] != s[i-1])  cnt++;
    }
    if(s[0]=='o'&&s[s.length()-1]=='o') cnt++;
    cout << (cnt%2 == 1 ? 'o' : 'x') << endl;
    return 0;
}