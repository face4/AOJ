#include<iostream>
using namespace std;

int main(){
    int n, m, a;
    cin >> n >> m;

    int x[n+1];
    for(int i = 0; i < n+1; i++)    x[i] = 0;

    int target[m];
    for(int i = 0; i < m; i++){
        cin >> target[i];
    }

    int b;
    for(int i = 0; i < m; i++){
        int hit = 0;
        for(int j = 1; j <= n; j++){
            cin >> b;
            if(b == target[i]){
                x[j]++;
                hit++;
            }
        }

        x[target[i]] += n-hit;
    }

    for(int i = 1; i <= n; i++) cout << x[i] << endl;

    return 0;
}