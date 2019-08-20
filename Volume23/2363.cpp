#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    double d[t+1] = {};
    for(int i = 0; i < t+1; i++){
        int n, m;
        cin >> n >> m;
        double a[m], b[m], sum = 0.0;
        for(int j = 0; j < m; j++){
            cin >> a[j] >> b[j];
            sum += b[j];
        }
        for(int j = 0; j < m; j++){
            d[i] += a[j]*b[j]/sum;
        }
    }
    for(int i = 0; i < t; i++){
        if(d[i] > d[t]+0.0000001){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
