#include<iostream>
using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int x[n];
    for(int i = 0; i < n; i++)  cin >> x[i];
    int d = 0;
    for(;d < n; d++){
        if(x[d] < a)   break;
    }
    if(n-d < m){
        while(d-1 >= 0 && x[d-1] <= b)  d--;
    }
    cout << d << endl;
    return 0;
}