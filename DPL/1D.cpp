#include<iostream>
using namespace std;

const int INF = 1<<30;

int getLISLen(int arr[], int n){
    int l[n];
    for(int i = 0; i < n; i++)  l[i] = INF;
    
    for(int i = 0; i < n; i++){
        *(lower_bound(l, l+n, arr[i])) = arr[i];
    }

    return (int)((lower_bound(l, l+n, INF))-l);
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    cout << getLISLen(a, n) << endl;
    
    return 0;
}