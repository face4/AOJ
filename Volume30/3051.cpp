#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b && a > c)  cout << "A";
    if(b > a && b > c)  cout << "B";
    if(c > a && c > b)  cout << "C";
    cout << endl;
    return 0;
}
