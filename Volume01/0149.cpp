#include<iostream>
using namespace std;

int classify(double d){
    if(d >= 1.1)    return 0;
    if(d >= 0.6)    return 1;
    if(d >= 0.2)    return 2;
    return 3;
}

int main(){
    int ans[4][2] = {};

    double l, r;
    while(cin >> l >> r){
        ans[classify(l)][0]++;
        ans[classify(r)][1]++;
    }

    for(int i = 0; i < 4; i++){
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }

    return 0;
}