#include<iostream>
using namespace std;

int main(){
    int sec = 0, tmp;
    while(cin >> tmp)   sec += tmp;
    cout << sec/60 << endl;
    cout << sec%60 << endl;
    return 0;
}