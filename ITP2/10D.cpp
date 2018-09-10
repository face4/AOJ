#include<iostream>
#include<bitset>
using namespace std;

int main(){
    int n;
    cin >> n;

    bitset<64> mask[n];
    for(int i = 0; i < n; i++){
        int k, b;
        cin >> k;
        while(k-- > 0){
            cin >> b;
            mask[i][b] = true;
        }
    }

    bitset<64> bs;
    int q, op, m;

    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> op >> m;
        if(op == 0) cout << bs[m] << endl;
        if(op == 1) bs |= mask[m];
        if(op == 2) bs &= ~mask[m];
        if(op == 3) bs ^= mask[m];
        if(op == 4) cout << ((bs&mask[m]) == mask[m]) << endl;
        if(op == 5) cout << (bs&mask[m]).any() << endl;
        if(op == 6) cout << (bs&mask[m]).none() << endl;
        if(op == 7) cout << (bs&mask[m]).count() << endl;
        if(op == 8) cout << (bs&mask[m]).to_ullong() << endl;        
    }
}