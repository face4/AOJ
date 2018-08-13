#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int q;
    cin >> q;

    int com, b, e;
    for(int i = 0; i < q; i++){
        cin >> com >> b >> e;
        int res;
        if(com == 0){
            res = INT_MAX;
            for(int i = b; i < e; i++)  res = min(res, a[i]);
        }else if(com == 1){
            res = INT_MIN;
            for(int i = b; i < e; i++)  res = max(res, a[i]);
        }
        cout << res << endl;
    }

    return 0;
}