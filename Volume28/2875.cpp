#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<bool> v(n+1, 0);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i], v[b[i]] = true;
    int val = -1;
    for(int i = 1; i <= n; i++){
        if(!v[i]){
            val = i;
            break;
        }
    }
    if(val == -1){
        cout << "Yes" << endl;
        return 0;
    }
    vector<int> c(n), d(n);
    for(int i = 0; i < n; i++){
        c[i] = i+1;
        if(a[i] == val) d[i] = (i+1)%n+1;
        else            d[i] = i+1;
    }
    cout << "No" << endl;
    for(int i = 0; i < n; i++)  cout << c[i] << " \n"[i+1==n];
    for(int i = 0; i < n; i++)  cout << d[i] << " \n"[i+1==n];
    return 0;
}