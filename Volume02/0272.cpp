#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++)  cin >> a[i];
        for(int i = 0; i < n; i++)  cin >> b[i];
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        vector<int> wod(n, 0); // opponent wins or draws
        int acur = 0, bcur = 0;
        while(acur < n && bcur < n){
            while(acur < n && b[bcur] < a[acur])    acur++;
            if(acur < n){
                wod[acur]++;
                bcur++;
            }
        }
        for(int i = 1; i < n; i++)  wod[i] += wod[i-1];
        int k;
        for(k = 0; k < n; k++){
            if((k+1) - wod[k] > (k+1)/2)    break;
        }
        if(k >= n-1)    cout << "NA" << endl;
        else            cout << k+1 << endl;
    }
    return 0;
}
