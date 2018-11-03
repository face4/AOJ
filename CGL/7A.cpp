#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    int dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    int r = (r1+r2)*(r1+r2);
    int rd = (max(r1,r2)-min(r1,r2))*(max(r1,r2)-min(r1,r2));

    if(dist > r)    cout << 4 << endl;
    else if(dist == r)  cout << 3 << endl;
    else if(dist == rd) cout << 1 << endl;
    else if(dist < rd)  cout << 0 << endl;
    else                cout << 2 << endl;

    return 0;
}