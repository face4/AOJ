#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double n;
    while(1){
        cin >> n;
        if(n < 0)   break;
        
        double integer;
        n = modf(n, &integer);
      
        int left = round(integer);
        
        if(left > 255){
            cout << "NA" << endl;
            continue;
        }
        
        int resinteger[8] = {};
        for(int i = 7; i >= 0; i--){
            resinteger[i] = left%2;
            left /= 2;
        }
        
        int resfloat[4] = {};
        double now = 0.5;
        for(int i = 0; i < 4; i++){
            if(n >= now){
                resfloat[i] = 1;
                n -= now;
            }
            now /= 2.0;
        }
        
        if(n == 0){
            for(int p : resinteger) cout << p;
            cout << ".";
            for(int p : resfloat)   cout << p;
            cout << endl;
        }else{
            cout << "NA" << endl;
        }
    }
    return 0;
}
