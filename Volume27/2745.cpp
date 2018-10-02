#include<iostream>
using namespace std;

int main(){
    int a, b, c, d;
    while(cin >> a >> b >> c >> d, a+b+c+d){
        cout << max(0,(b*c-a+d-1))/d << endl;
    }
    return 0;
}