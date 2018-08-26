#include<iostream>
using namespace std;

int main(){
    int n, m;
    string s;
    while(cin >> n, n){
        cin >> m >> s;
        int ans = 0;
        for(int i = 0; i < m-2; i++){
            if(s.substr(i, 3) == "IOI"){
                int tmp = 1;
                i += 2;
                while(i+1 < m-1 && s.substr(i+1, 2) == "OI"){
                    i += 2;
                    tmp++;
                }
                ans += max(0, tmp-n+1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}