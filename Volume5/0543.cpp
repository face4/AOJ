#include<iostream>
using namespace std;

int main(){
    int n, x;
    while(cin >> n, n){
        for(int i = 0; i < 9; i++){
            cin >> x;
            n -= x;
        }
        cout << n << endl;
    }
    return 0;
}