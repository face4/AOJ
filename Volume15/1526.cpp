#include<iostream>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int slen = s.length(), tlen = t.length();
    for(int i = 0; i <= slen-tlen; i++){
        bool valid = true;
        for(int j = 0; valid && j < tlen; j++){
            valid &= (s[i+j] == t[j] || t[j] == '_');
        }
        if(valid){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}