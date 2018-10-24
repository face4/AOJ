#include<iostream>
using namespace std;

int main(){
    int n, c;
    cin >> n >> c;

    int sum = 0, p;
    for(int i = 0; i < c; i++){
        cin >> p;
        sum += p;
    }

    cout << (sum + n) / (n+1) << endl;
    return 0;
}