#include<iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    while(x-- > 0){
        int p, q;
        cin >> p >> q;
        int sq = p*p+q*q;
        int cnt = 0;
        for(int m = -150; m <= 150; m++){
            for(int n = -150; n <= 150; n++){
                if(m*m+n*n==0 || sq%(m*m+n*n))    continue;
                int c = m*m+n*n;
                bool a = (m*p+n*q)%c == 0;
                bool b = (m*q-n*p)%c == 0;
                if(a && b)  cnt++;
            }
        }
        cout << (cnt==8 ? "P" : "C") << endl;
    }
    return 0;
}