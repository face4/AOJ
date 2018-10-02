#include<iostream>
using namespace std;

int n;
string s = "";

bool exists(string t){
    for(int i = 0; i <= s.length()-t.length(); i++){
        if(t == s.substr(i, t.length()))    return true;
    }
    return false;
}

int main(){
    cin >> n;
    
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        s += c;
    }

    int ans = 0;
    while(exists(to_string(ans)))    ans++;

    cout << ans << endl;

    return 0;
}