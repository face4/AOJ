#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

#define DEGtoRAD(X) (X*PI)/180.0
#define Equals(a, b) (fabs(a-b) < EPS)

const double PI = 2 * acos(0.0);
const double EPS = 1e-9;

struct point{
    double x, y;
    point(){ x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator < (const point other) const{
        if(fabs(x - other.x) > EPS)
            return x < other.x;
        else
            return y < other.y;
    }

    bool operator == (const point other) const{
        return Equals(x,other.x) && Equals(y,other.y);
    }

    point operator + (point &p){
        return point(x + p.x, y + p.y);
    }

    point operator - (point &p){
        return point(x - p.x, y - p.y);
    }

    point operator * (double k){
        return point(x * k, y * k);
    }
};

// 2つのpoint間の距離 std::hypotenuse(斜辺)を利用
double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

/* -------------------------------------------------- */

typedef point vec;

double dot(vec v1, vec v2){
    return v1.x * v2.x + v1.y * v2.y;
}

double cross(vec v1, vec v2){
    return v1.x * v2.y - v1.y * v2.x;
}

bool isOrthogonal(vec v1, vec v2){
    return Equals(dot(v1, v2), 0.0);
}
bool isOrthogonal(point a1, point a2, point b1, point b2){
    return isOrthogonal(a1-a2, b1-b2);
}

bool isParallel(vec v1, vec v2){
    return Equals(cross(v1, v2), 0.0);
}
bool isParallel(point a1, point a2, point b1, point b2){
    return isParallel(a1-a2, b1-b2);
}

int main(){
    int q;
    cin >> q;

    double x[8];

    while(q-- > 0){
        for(int i = 0; i < 8; i++)  cin >> x[i];
        point a(x[0], x[1]), b(x[2],x[3]), c(x[4],x[5]), d(x[6],x[7]);
        
        if(isOrthogonal(a,b,c,d))       cout << 1 << endl;
        else if(isParallel(a,b,c,d))    cout << 2 << endl;
        else                            cout << 0 << endl;

    }

    return 0;
}