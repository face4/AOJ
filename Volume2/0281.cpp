#include<iostream>
using namespace std;

int main(){
    int q, c, a, n;
    cin >> q;
    while(q-- > 0){
        cin >> c >> a >> n;
        int can, cca, ccc;
        
        can = min(c, min(a,n));
        c -= can, a -= can, n -= can;
        
        cca = min(c/2, a);
        c -= cca*2, a -= cca;
        
        ccc = c/3;
        c -= ccc*3;
        
        cout << can+cca+ccc << endl;
    }
    return 0;
}
