#include<iostream>
#include<bitset>
using namespace std;

int main(){
    bitset<64> bs;
    int q;
    cin >> q;

    int op, i;
    while(q-- > 0){
        cin >> op;
        if(op == 0) scanf("%d", &i), cout << bs[i] << endl;
        if(op == 1) scanf("%d", &i), bs[i] = true;
        if(op == 2) scanf("%d", &i), bs[i] = false;
        if(op == 3) scanf("%d", &i), bs[i] = !bs[i];
        if(op == 4) printf("%d\n", bs.all());
        if(op == 5) printf("%d\n", bs.any());
        if(op == 6) printf("%d\n", bs.none());
        if(op == 7) printf("%d\n", bs.count());
        if(op == 8) printf("%llu\n", bs.to_ullong());
    }

    return 0;
}