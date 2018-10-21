#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n, seq = 1;
    while(cin >> n, n){
        int x[n], y[n];
        double area = 0;
        for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];

        for(int i = 0; i < n; i++){
            area += (y[(i+1)%n]*x[i])-(x[(i+1)%n]*y[i]);
        }

        cout << seq++ << " " << fixed << setprecision(1) << -area/2.0 << endl;
    }
    return 0;
}