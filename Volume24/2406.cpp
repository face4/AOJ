#include<iostream>
using namespace std;

int main(){
    int n, t, e;
    cin >> n >> t >> e;
    int x[n];
    for(int i = 0; i < n; i++)  cin >> x[i];
    for(int i = 0; i < n; i++){
        if(abs(t/x[i]*x[i]-t) <= e || abs((t/x[i]+1)*x[i]-t) <= e){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}