#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;

    int cur = 0;

    while(cur <= (int)s.length()-8){
        string t = s.substr(cur, 8);
        sort(t.begin(), t.end());
        if(t == "AADINNUY"){
            for(int i = 0; i < 8; i++){
                s[cur++] = "AIZUNYAN"[i];
            }
        }else{
            cur++;
        }
    }

    cout << s << endl;

    return 0;
}