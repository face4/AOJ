#include<iostream>
#include<cctype>
using namespace std;

int enc(char c){
    if(islower(c))  return c-'a';
    else            return 26 + c - 'A';
}

char dec(int i){
    if(i <= 25) return 'a'+i;
    else        return 'A' + i-26;
}

int main(){
    int n;
    while(cin >> n, n){
        int key[n];
        for(int i = 0; i < n; i++)  cin >> key[i];
        string s;
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            cout << dec((enc(s[i])+52-key[i%n])%52);
        }
        cout << endl;
    }
    return 0;
}