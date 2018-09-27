#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n, w, h;
    cin >> n >> w >> h;

    int width[w+1], height[h+1];
    memset(height, 0, sizeof(height));
    memset(width, 0, sizeof(width));

    int x, y, a;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> a;
        width[max(0, x-a)]++;
        width[min(w, x+a)]--;
        height[max(0, y-a)]++;
        height[min(h, y+a)]--;
    }

    bool judgew = true, judgeh = true;
    
    int acc = 0;
    for(int i = 0; i < w; i++){
        acc += width[i];
        if(acc <= 0)    judgew = false;
    }

    acc = 0;
    for(int i = 0; i < h; i++){
        acc += height[i];
        if(acc <= 0)    judgeh = false;
    }

    if(judgew || judgeh)    cout << "Yes" << endl;
    else                    cout << "No" << endl;
    
    return 0;
}