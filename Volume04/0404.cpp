#include<iostream>
using namespace std;

int main(){
    int s = 0;
    for(int i = 0; i < 4; i++){
        int x;  cin >> x;
        s += x;
    }
    cout << s << endl;
    return 0;
}