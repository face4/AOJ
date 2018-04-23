#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double th = M_PI * 60.0 / 180.0;

struct Point {
    double x;
    double y;
};

void printP(Point p){
    cout << fixed << setprecision(8) << p.x << " ";
    cout << fixed << setprecision(8) << p.y << endl;
}

void koch(int n, Point a, Point b){
    if(n == 0)  return;

    Point s, t, u;

    s.x = (2.0*a.x + 1.0*b.x) / 3.0;
    s.y = (2.0*a.y + 1.0*b.y) / 3.0;
    t.x = (1.0*a.x + 2.0*b.x) / 3.0;
    t.y = (1.0*a.y + 2.0*b.y) / 3.0;
    u.x = (t.x-s.x)*cos(th) - (t.y-s.y)*sin(th) + s.x;
    u.y = (t.x-s.x)*sin(th) + (t.y-s.y)*cos(th) + s.y;
    
    koch(n-1, a, s);
    printP(s);
    koch(n-1, s, u);
    printP(u);
    koch(n-1, u, t);
    printP(t);
    koch(n-1, t, b);
}

int main(){
    Point a, b;
    int n;

    cin >> n;

    a.x = 0;
    a.y = 0;
    b.x = 100;
    b.y = 0;

    printP(a);
    koch(n,a,b);
    printP(b);

    return 0;
}