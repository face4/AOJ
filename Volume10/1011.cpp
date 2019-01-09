// 手で書いて漸化式を導いた(階差数列を用いた漸化式の導出をすっかり忘れていて焦った.)
#include<iostream>
using namespace std;

int p(int x, int y){
    int ret = 1;
    while(y-- > 0)  ret *= x;
    return ret;
}

int main(){
    int n;
    while(cin >> n){
        int ret = 0;
        if(n%2){
            ret = 2*p(3,n/2+1-1) - 1;
        }else{
            ret = p(3,n/2) - 1;
        }
        cout << ret << endl;
    }
    return 0;
}