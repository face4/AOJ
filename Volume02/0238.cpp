#include<iostream>
using namespace std;

int main(){
    while(1){
        int t, n, s, f;
        cin >> t;
        
        if(t == 0)  break;
        cin >> n;
        
        int actual = 0;
        while(n-- > 0){
            cin >> s >> f;
            actual += f-s;
        }
        
        if(actual >= t) cout << "OK" << endl;
        else            cout << t-actual << endl;
    }
    return 0;
}
