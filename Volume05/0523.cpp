#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        bool t[2*n+1], h[2*n+1];
        int taro = n, hana = n;
        
        for(int i = 0; i <= 2*n; i++)
            t[i] = false;
        
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            t[x] = true;
        }
        for(int i = 1; i <= 2*n; i++)
            h[i] = !t[i];
        
        bool turn = true;
        int ba = 0;
        while(taro != 0 && hana != 0){
            if(turn){
                int next;
                for(next = ba+1; next <= 2*n; next++){
                    if(t[next]){
                        t[next] = false;
                        break;
                    }
                }
                if(next <= 2*n){
                    ba = next;
                    taro--;
                }else{
                    ba = 0;
                }
            }else{
                int next;
                for(next = ba+1; next <= 2*n; next++){
                    if(h[next]){
                        h[next] = false;
                        break;
                    }
                }
                if(next <= 2*n){
                    ba = next;
                    hana--;
                }else{
                    ba = 0;
                }
            }
            turn = !turn;
        }
        
        cout << hana << endl << taro << endl;
    }
    return 0;
}
