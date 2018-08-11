#include<iostream>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0)  break;
        
        int s[n], p[n], q[n], r[n], c[n];
        int P, Q, R, C;
        
        for(int i = 0; i < n; i++){
            cin >> s[i] >> p[i] >> q[i] >> r[i];
            c[i] = 4*p[i] + 9*q[i] + 4*r[i];
        }
        
        cin >> P >> Q >> R >> C;
        
        bool found = false;
        for(int i = 0; i < n; i++){
            if(p[i] <= P && q[i] <= Q && r[i] <= R && c[i] <= C){
                found = true;
                cout << s[i] << endl;
            }
        }
        
        if(!found)  cout << "NA" << endl;
    }
    return 0;
}
