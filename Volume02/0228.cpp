#include<iostream>
using namespace std;

int seg[10][7] = {
    {0,1,1,1,1,1,1},
    {0,0,0,0,1,1,0},
    {1,0,1,1,0,1,1},
    {1,0,0,1,1,1,1},
    {1,1,0,0,1,1,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,1,0,1},
    {0,1,0,0,1,1,1},
    {1,1,1,1,1,1,1},
    {1,1,0,1,1,1,1}
};

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == -1) break;
        
        int now[7] = {};
        
        while(n-- > 0){
            int next;
            cin >> next;
            for(int i = 0; i < 7; i++){
                cout << (now[i] ^ seg[next][i]);
                now[i] = seg[next][i];
            }
            cout << endl;
        }
        
    }
    
    return 0;
}
