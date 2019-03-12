#include<iostream>
using namespace std;

int main(){
    int r, c;
    while(cin >> r >> c, r+c){
        cout << (r%2 + c%2 == 2 ? "no" : "yes") << endl;
    }
    return 0;
}