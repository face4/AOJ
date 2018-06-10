#include<iostream>
using namespace std;

int main(){
    int n, A[45];
    cin >> n;
    A[0] = 1;
    A[1] = 1;
    for(int i = 2; i <= n; i++) A[i] = A[i-1] + A[i-2];
    cout << A[n] << endl;
    return 0;
}