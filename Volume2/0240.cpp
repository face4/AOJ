#include<iostream>
#include<cmath>
using namespace std;

int main(){
    while(1){
        int n, y;
        cin >> n;
        
        if(n == 0)  break;
        
        cin >> y;
        
        int ans = -1;
        double maxmoney = -1;
        
        int b, r, t;
        for(int i = 0; i < n; i++){
            cin >> b >> r >> t;
            double tmpmoney = 1.0;
            
            if(t == 1){
                tmpmoney *= (1.0 + y*r/100.0);
            }else if(t == 2){
                tmpmoney *= pow(1.0 + r/100.0, y);
            }
            
            if(tmpmoney > maxmoney){
                ans = b;
                maxmoney = tmpmoney;
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}
