#include<iostream>
using namespace std;

int main(){
    int x, y;
    while(1){
        cin >> x >> y;
        if(x+y == 0)    break;
        
        int r[4], a[4];
        for(int i = 0; i < 4; i++){
            r[3-i] = x%10;  x /= 10;
            a[3-i] = y%10;  y /= 10;
        }
        
        int hit = 0, blow = 0;
        for(int i = 0; i < 4; i++){
            if(r[i] == a[i]){
                hit++;
                r[i] = a[i] = -1;
            }
        }
        
        for(int i = 0; i < 4; i++){
            if(r[i] == -1)  continue;
            for(int j = 0; j < 4; j++){
                if(i == j)  continue;
                if(r[i] == a[j]){
                    blow++;
                    break;
                }
            }
        }
        
        cout << hit << " " << blow << endl;
    }
    return 0;
}
