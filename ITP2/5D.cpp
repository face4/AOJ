#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0; i < n; i++)  a[i] = i+1;

    do{
        printf("%d", a[0]);
        for(int i = 1; i < n; i++)  printf(" %d", a[i]);
        printf("\n");
    }while(next_permutation(a, a+n));

    return 0;
}