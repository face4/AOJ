#include<iostream>
using namespace std;

int a[5] = {5,7,5,7,7};

int main(){
    int n;
    while(cin >> n, n){
        int w[n];
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            w[i] = s.length();
        }
        
        int ans;

        for(int i = 0; i < n; i++){
            int pos = 0, tmplen = 0;
            for(int j = i; j < n; j++){
                if(tmplen < a[pos]) tmplen += w[j];
                if(tmplen > a[pos]) break;
                if(tmplen == a[pos])    pos++, tmplen = 0;
                if(pos == 5){
                    ans = i;
                    break;
                }
            }
            if(pos == 5)    break;
        }

        cout << ans+1 << endl;
    }
    return 0;
}