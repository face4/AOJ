#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1;; i++){
        int cnt = 0;
        for(int j = 1; j*j <= i; j++){
            if(i%j) continue;
            cnt+=2;
            if(j*j == i)    cnt--;
        }
        if(cnt == n){
            cout << i << endl;
            return 0;
        }
    }
}