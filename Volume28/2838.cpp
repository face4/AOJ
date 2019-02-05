#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    s = "A" + s;
    int cnt = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[i-1] >= s[i])  cnt++;
    }
    cout << cnt << endl;
    return 0;
}