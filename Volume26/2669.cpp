#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    string o = "AZ";
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == o[cnt%2])    cnt++;
    }

    if(cnt%2)   cnt--;
    if(cnt == 0)    cout << -1;
    else            for(int i = 0; i < cnt/2; i++)  cout << "AZ";
    cout << endl;

    return 0;
}