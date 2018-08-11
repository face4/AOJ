#include<iostream>
using namespace std;

int main(){
    int w, h, n;
    cin >> w >> h >> n;

    int x, y;
    cin >> x >> y;
    int step = 0;

    for(int i = 1; i < n; i++){
        int dx, dy;
        cin >> dx >> dy;

        int tmp = (x-dx)*(y-dy);
        if(tmp > 0){
            step += max(abs(x-dx), abs(y-dy));
        }else if(tmp == 0){
            step += max(abs(x-dx), abs(y-dy));
        }else if(tmp < 0){
            step += abs(x-dx) + abs(y-dy);
        }

        x = dx;
        y = dy;
    }

    cout << step << endl;

    return 0;
}