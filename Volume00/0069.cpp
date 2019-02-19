#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int m, g, d;  cin >> m >> g >> d;
        int amida[d][n+1];
        memset(amida, 0, sizeof(amida));

        for(int i = 0; i < d; i++){
            for(int j = 1; j < n; j++){
                char x; cin >> x;
                amida[i][j] = x-'0';
            }
        }

        int now = m;
        for(int i = 0; i < d; i++){
            if(amida[i][now-1]) now--;
            else if(amida[i][now])    now++;
        }

        if(now == g){
            cout << 0 << endl;
            continue;
        }

        now = m;
        int ansa = 0, ansb = 0;
        for(int i = 0; i < d; i++){
            if(amida[i][now-1]){
                now--;
            }else if(amida[i][now]){
                now++;
            }else{
                int tmp = now-1;
                if(tmp != 0 && amida[i][tmp-1] == 0){
                    for(int j = i+1; j < d; j++){
                        if(amida[j][tmp-1]) tmp--;
                        else if(amida[j][tmp])    tmp++;
                    }
                    if(tmp == g){
                        ansa = i+1, ansb = now-1;
                        break;
                    }
                }
                tmp = now;
                if(tmp != n && amida[i][tmp+1] == 0){
                    tmp++;
                    for(int j = i+1; j < d; j++){
                        if(amida[j][tmp-1]) tmp--;
                        else if(amida[j][tmp])    tmp++;
                    }
                    if(tmp == g){
                        ansa = i+1, ansb = now;
                        break;
                    }
                }
            }
        }

        if(ansa == 0){
            cout << 1 << endl;
        }else{
            cout << ansa << " " << ansb << endl;
        }

    }
    return 0;
}