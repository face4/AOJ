#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int d[9], a[9];
    for(int i = 0; i < 9; i++)  cin >> a[i];
    for(int i = 0; i < 9; i++)  d[i] = i+1;

    int ans = 0;
    do{
        bool judge = true;
        for(int i = 0; i < 9; i++)  if(a[i] != -1 && a[i] != d[i])  judge = false;
        if(!judge)  continue;

        int plus = d[0] + 10*d[1] + d[2] + 100*d[3] + 10*d[4] + d[5];
        int res = 100*d[6] + 10*d[7] + d[8];
        if(plus == res) ans++;
    }while(next_permutation(d, d + 9));

    cout << ans << endl;
    return 0;
}