// ???
#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int m, n;
    cin >> m >> n;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    if(m == 2){
        int ret = 1<<30;
        for(int i = 1; i <= 2; i++){
            int x = i;
            int tmp = 0;
            for(int j = 0; j < n; j++){
                tmp += a[j]!=x;
                x = 3-x;
            }
            ret = min(ret, tmp);
        }
        cout << ret << endl;
        return 0;
    }
    int ret = 0;
    for(int i = 1; i < n; i++){
        if(a[i]==a[i-1]){
            a[i] = -1;
            ret++;
        }
    }
    cout << ret << endl;
    return 0;
}

