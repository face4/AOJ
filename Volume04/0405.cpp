#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int n;
    cin >> n;
    if(inRange(n, 65, 90))          cout << 1 << endl;
    else if(inRange(n, 97, 122))    cout << 2 << endl;
    else                            cout << 0 << endl;
    return 0;
}