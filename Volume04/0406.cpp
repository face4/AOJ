#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ret = 1;
    while(ret*2 <= n)   ret *= 2;
    cout << ret << endl;
    return 0;
}