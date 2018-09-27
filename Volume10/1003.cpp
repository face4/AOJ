#include<iostream>
using namespace std;

string f[9] = {"',.!?", "abcABC", "defDEF", "ghiGHI",
                "jklJKL", "mnoMNO", "pqrsPQRS", "tuvTUV", "wxyzWXYZ"};
    
int main(){
    string s;
    while(cin >> s){
        int n = s.length();
        int index = 0;
        string res = "";
        while(index < n){
            char now = s[index];
            if(now == '0'){
                res += " ";
                index++;
            }else{
                int cnt = 0;
                while(index < n && now == s[index]) index++, cnt++;
                int x = now-'0'-1;
                res += f[x][(cnt-1)%(f[x].length())];
                if(s[index] == '0') index++;
            }
        }
        cout << res << endl;
    }
    return 0;
}