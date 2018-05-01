#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n+1] = {};
    int B[n+1];
    int C[10001] = {};

    for(int i = 0; i < n; i++){
        cin >> A[i+1];
        C[A[i+1]]++;
    }

    for(int i = 1; i <= 10000; i++){
        C[i] += C[i-1];
    }

    for(int i = n; i >= 1; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    for(int i = 1; i <= n; i++){
        if(i != 1)  cout << " ";
        cout << B[i];
    }

    cout << endl;
    return 0;
}