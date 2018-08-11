#include<iostream>
using namespace std;

int main(){
    int w;
    while(cin >> w){
        if(w == -1) break;

        int ans = 1150;
        ans += max(0, min(w-10 , 10)) * 125;
        ans += max(0, min(w-20 , 10)) * 140;
        ans += max(0, w-30) * 160;

        cout << 4280-ans << endl;
    }
    return 0;
}