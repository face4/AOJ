// code by face4

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

// 度->ラジアンの変換
#define DEGtoRAD(X) (X*PI)/180.0
#define Equals(a, b) (fabs(a-b) < EPS)

// 円周率
const double PI = 2 * acos(0.0);
// 許容誤差.問題によって変える
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

// 2つのpoint a,b をvec a->b に変換
vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

// pointとvecの和
point translate(point p, vec v){
    return point(p.x + v.x, p.y + v.y);
}

// vecの内積
double dot(vec v1, vec v2){
    return v1.x * v2.x + v1.y * v2.y;
}

// vecの外積
double cross(vec v1, vec v2){
    return v1.x * v2.y - v1.y * v2.x;
}

// vecの2ノルムの2乗
double norm_sq(vec v){
    return v.x * v.x + v.y * v.y;
}

double distToLine(point p, point a, point b, point &c){
    vec ap = toVec(a, p);
    vec ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, ab*u);
    return dist(p, c);
}

int main(){
    double x1, y1, x2, y2;
    int q;
    double x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> q;

    point s(x1,y1), t(x2,y2);

    while(q-- > 0){
        cin >> x >> y;
        point p(x,y), ans;
        distToLine(p, s, t, ans);
        cout << fixed << setprecision(10) << ans.x << " " << ans.y << endl;
    }

    return 0;
}