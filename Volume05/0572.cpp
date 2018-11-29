#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    int s[a], t[b];
    for(int i = 0; i < a; i++)  cin >> s[i];
    for(int i = 0; i < b; i++)  cin >> t[i];

    int ans = 0;
    for(int i = 0; i < b; i++){
        int posa = 0, posb = i;
        while(posa < a && posb < b){
            if(s[posa] == t[posb])   posb++;
            posa++;
        }
        ans = max(ans, posb-i);
    }
    
    cout << ans << endl;

    return 0;
}