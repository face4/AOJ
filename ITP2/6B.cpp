#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++)  cin >> b[i];

    int bpos, apos = 0;
    for(bpos = 0; bpos < m; bpos++){
        while(apos < n && b[bpos] > a[apos])    apos++;
        if(apos != n && b[bpos] == a[apos]) continue;
        else    break;
    }

    cout << (bpos==m) << endl;

    return 0;
}