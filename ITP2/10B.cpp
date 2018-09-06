#include<iostream>
#include<bitset>
using namespace std;

int main(){
    unsigned int a, b;
    cin >> a >> b;
    bitset<32> x(a), y(b);
    cout << (x&y) << endl << (x|y) << endl << (x^y) << endl;
    return 0;
}