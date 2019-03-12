#include<iostream>
using namespace std;

int main(){
    int n, s, d;
    cin >> n;
    while(n-- > 0){
        cin >> s >> d;
        int ans = 0;
        while(s != d){
            int p;
            for(int i = 0; i < 31; i++){
                if(s%(1<<i) == 0 && s+(1<<i) <= d)   p = i;
            }
            ans++;
            s += (1<<p);
        }
        cout << ans << endl;
    }
    return 0;
}