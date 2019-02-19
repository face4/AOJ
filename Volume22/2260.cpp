#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int cnt = n/2;
    for(int i = 0; i < n/2; i++){
        if((s[i]==s[n-1-i]&&(s[i]=='i'||s[i]=='w')) || (s[i]=='('&&s[n-1-i]==')') || (s[i]==')'&&s[n-1-i]=='(')) cnt--;
    }
    if(n%2 == 1 && (s[n/2]=='(' || s[n/2]==')'))    cnt++;
    cout << cnt << endl;
    return 0;
}