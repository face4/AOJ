#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int ret = 0;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    int bef = 1<<30;
    for(int i = 0; i < n; i++){
        if(bef < a[i]){
            bef = a[i];
            continue;
        }else{
            ret++;
            bef = a[i];
        }
    }
    cout << ret << endl << n << endl;
    return 0;
}
