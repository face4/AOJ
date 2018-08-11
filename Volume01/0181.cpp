#include<iostream>
using namespace std;

int m, n;
int w[100];

bool check(int mid){
    int tmpm = 1, nowp = 0;
    for(int i = 0; i < n; i++){
        if(mid < w[i])  return false;

        if(nowp + w[i] <= mid){
            nowp += w[i];
        }else{
            nowp = w[i];
            tmpm++;
        }
    }
    return tmpm <= m;
}

int main(){
    while(1){
        cin >> m >> n;

        if(m + n == 0)  break;

        int minp = 1000001;
        for(int i = 0; i < n; i++){
            cin >> w[i];
            minp = min(minp, w[i]); 
        }

        int l = minp, r = 1500000;

        while(r-l > 1){
            int mid = (r+l) / 2;
            if(check(mid))  r = mid;
            else            l = mid;
        }

        cout << (check(l) ? l : r) << endl;
    }

    return 0;
}