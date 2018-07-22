#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int d[n];
    for(int i = 0; i < n; i++)  cin >> d[i];

    bool judge = true;
    int res = d[0];

    int i;
    for(i = 1; i < n; i++){
        res -= 10;
        if(res < 0) break;
        res = max(res, d[i]);
    }

    if(i != n || res < 0)  judge = false;

    res = d[n-1];
    for(i = n-2; i >= 0; i--){
        res -= 10;
        if(res < 0) break;
        res = max(res, d[i]);
    }

    if(i != -1 || res < 0)  judge = false;

    if(judge)   cout << "yes" << endl;
    else        cout << "no" << endl;

    return 0;
}