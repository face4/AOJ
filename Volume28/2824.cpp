#include<iostream>
using namespace std;

int main(){
    int t, d, l, x;
    while(cin >> t >> d >> l, t+d+l){
        int rest = 0, ans = 0;
        while(t-- > 0){
            cin >> x;
            if(x >= l)  rest = d;
            if(rest > 0){
                ans++;
                rest--;
            }
        }
        cout << max(ans-1, 0) << endl;
    }
    return 0;
}