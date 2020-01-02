#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int happy = 0;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 1; i < n; i++)  happy += a[i]>a[i-1];
    cout << happy << endl;
    return 0;
}
