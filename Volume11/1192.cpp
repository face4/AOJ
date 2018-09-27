#include<iostream>
using namespace std;

int tax(int n, int r){
    return n * (100+r) / 100;
}

int main(){
    int x, y, s;
    while(cin >> x >> y >> s, x+y+s){
        int ans = 0;
        for(int i = 1; i <= s-1; i++){
            for(int j = 1; j <= s-1; j++){
                if(tax(i,x) + tax(j,x) == s){
                    ans = max(ans, tax(i,y)+tax(j,y));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}