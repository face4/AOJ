#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    for(int i = 1; i <= m; i++){
        for(int j = 0; j < n-1; j++){
            if(a[j]%i > a[j+1]%i)   swap(a[j], a[j+1]);
        }
    }

    for(int i : a)  cout << i << endl;

    return 0;
}