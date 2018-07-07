#include<iostream>
using namespace std;

int main(){

    int dist[8] = {0, 0, 6, 13, 18, 23, 43, 58};
    int fee[8][8] = {};
    fee[1][2] = 300;    fee[2][3] = 350;    fee[3][4] = 250;    fee[4][5] = 250;    fee[5][6] = 600;    fee[6][7] = 500;
    fee[1][3] = 500;    fee[2][4] = 450;    fee[3][5] = 400;    fee[4][6] = 850;    fee[5][7] = 1150;
    fee[1][4] = 600;    fee[2][5] = 600;    fee[3][6] = 1000;   fee[4][7] = 1300;   
    fee[1][5] = 700;    fee[2][6] = 1150;   fee[3][7] = 1350;   
    fee[1][6] = 1350;   fee[2][7] = 1500;   
    fee[1][7] = 1650;   
    int d, hd, md, a, ha, ma;
    while(1){
        cin >> d;
        if(d == 0)  break;
        cin >> hd >> md >> a >> ha >> ma;
        hd = hd*100 + md;
        ha = ha*100 + ma;
        
        int distance = dist[a] - dist[d];
        int ans = fee[d][a];
        if(distance <= 40){
            if((1730 <= hd && hd <= 1930) || (1730 <= ha && ha <= 1930)){
                ans /= 2;
                ans = (ans % 50 == 0) ? ans : (ans/50+1)*50; 
            }
        }

        cout << ans << endl;
    }
    return 0;
}