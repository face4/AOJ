#include<iostream>
using namespace std;

bool ok(int *a){
    int sum = 0;
    for(int i = 1; i <= 11; i++){
        int j;
        if(i <= 6)  j = i+1;
        else        j = i-5;
        sum += a[11-i]*j;
    }
    if(sum%11 <= 1) return 0 == a[11];
    return a[11]==11-sum%11;
}

int main(){
    int a[12], ind = -1;
    for(int i = 0; i < 12; i++){
        char c; cin >> c;
        if(c == '?')    ind = i;
        else            a[i] = c-'0';
    }
    int ret = -1;
    for(int i = 0; i <= 9; i++){
        a[ind] = i;
        if(ok(a)){
            if(ret != -1){
                cout << "MULTIPLE" << endl;
                return 0;
            }
            ret = i;
        }
    }
    cout << ret << endl;
    return 0;
}