#include<iostream>
using namespace std;

int main(){
    bool isHamming[1000001] = {};
    isHamming[1] = true;
    for(int i = 1; i <= 1000000; i++){
        if(isHamming[i]){
            if(i*2 <= 1000000)  isHamming[i*2] = true;
            if(i*3 <= 1000000)  isHamming[i*3] = true;
            if(i*5 <= 1000000)  isHamming[i*5] = true;
        }
    }

    int m, n;
    while(1){
        cin >> m >> n;
        if(m == 0)  break;

        int cnt = 0;
        for(int i = m; i <= n; i++) if(isHamming[i])    cnt++;
        cout << cnt << endl;
    }
    return 0;
}