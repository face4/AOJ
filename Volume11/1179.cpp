#include<iostream>
using namespace std;

int calc(int y, int m, int d){
    int ret = (y-1)/3 * 200 + (y-1 - (y-1)/3) * 195;
    if(y % 3 == 0)  ret += 20*(m-1);
    else            for(int i = 1; i < m; i++)  ret += 19 + (i%2 == 1);
    ret += d;
    return ret;
}

int main(){
    int n, y, m, d;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> y >> m >> d;
        cout << calc(1000,1,1) - calc(y,m,d) << endl;
    }

    return 0;
}