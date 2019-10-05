#include<iostream>
using namespace std;

#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int x, y;
    cin >> x >> y;
    int lx = 0, rx = 0, ly = 0, ry = 0, col = 0, turn = 0;
    while(!inRange(x,lx,rx) || !inRange(y,ly,ry)){
        col = (col+1)%3;
        if(turn == 0)   rx += ry-ly+1;   
        if(turn == 1)   ry += rx-lx+1;
        if(turn == 2)   lx -= ry-ly+1;
        if(turn == 3)   ly -= rx-lx+1;
        turn = (turn+1)%4;
    }
    cout << col+1 << endl;
    return 0;
}