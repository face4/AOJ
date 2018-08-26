#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    if(prev_permutation(a, a+n)){
        for(int i = 0; i < n; i++)  cout << a[i] << " \n"[i == n-1];
    }
    next_permutation(a, a+n);

    for(int i = 0; i < n; i++)  cout << a[i] << " \n"[i == n-1];

    if(next_permutation(a, a+n)){
        for(int i = 0; i < n; i++)  cout << a[i] << " \n"[i == n-1];
    }

    return 0;
}