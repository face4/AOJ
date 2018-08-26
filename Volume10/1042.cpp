#include<iostream>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        if(s == "END OF INPUT") break;
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' ') cnt++;
            else            cout << cnt, cnt = 0;
        }
        cout << cnt << endl;
    }   
    return 0; 
}