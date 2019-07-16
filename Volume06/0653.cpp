#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[n];
    bool used[2100] = {};
    for(int i = 0; i < n; i++){
        cin >> x[i];
        used[x[i]] = true;
    }
    int m;
    cin >> m;
    while(m-- > 0){
        int k;
        cin >> k;
        k--;
        if(x[k] != 2019 && !used[x[k]+1]){
            used[x[k]] = false;
            x[k]++;
            used[x[k]] = true;
        }
    }
    for(int i = 0; i < n; i++)  cout << x[i] << endl;
    return 0;
}