#include<iostream>
using namespace std;

int main(){
    bool nonprime[1000001] = {};
    nonprime[0] = nonprime[1] = true;
    for(int i = 2; i <= 1000000; i++){
        if(!nonprime[i]){
            for(int j = i+i; j <= 1000000; j += i){
                nonprime[j] = true;
            }
        }
    }
    
    while(1){
        int n, x;
        cin >> n >> x;
        
        if(n + x == 0)  break;
    
        bool valid[x+1] = {};
        valid[0] = true;
        
        int v;
        for(int i = 0; i < n; i++){
            cin >> v;
            for(int j = 0; j <= x-v; j++){
                if(valid[j])    valid[j+v] = true;
            }
        }
        
        int ans = -1;
        for(int i = x; i >= 1; i--){
            if(valid[i] && !nonprime[i]){
                ans = i;
                break;
            }
        }
        
        if(ans == -1)   cout << "NA" << endl;
        else            cout << ans << endl;
    }
    return 0;
}

