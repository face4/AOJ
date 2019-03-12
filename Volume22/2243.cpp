#include<iostream>
using namespace std;

int main(){
    string s;
    while(cin >> s, s != "#"){
        string t = "";
        for(char x : s){
            char y = ('0' + (x-'1')%3);
            t += y;
        }
        int ans = s.length();
        for(int i = 0; i < 2; i++){
            int turn = i, score = 0;
            for(int j = 1; j < t.length(); j++){
                if((t[j]-t[j-1])*(2*turn-1) >= 0){
                    turn = 1-turn;
                }else{
                    score++;
                }
            }
            ans = min(ans, score);
        }
        cout << ans << endl;
    }
    return 0;
}