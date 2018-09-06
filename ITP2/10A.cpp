#include<iostream>
#include<bitset>
using namespace std;

int main(){
    // unsigned intでも可
    long long x;
    cin >> x;
    bitset<32> a(x);
    cout << a << "\n" << ~a << "\n" << (a<<1) << "\n" << (a>>1) << "\n";
    return 0;
}