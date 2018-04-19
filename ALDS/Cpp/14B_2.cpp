#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int A[100001], n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    int q, k, sum = 0;
    cin >> q;
    for(int i = 0; i < q; i++){
        scanf("%d", &k);
        if(*lower_bound(A, A+n, k) == k){
            sum++;
        }
    }

    cout << sum << endl;
    return 0;
}