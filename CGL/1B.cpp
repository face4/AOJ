#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

// 度->ラジアンの変換
#define DEGtoRAD(X) (X*PI)/180.0
#define Equals(a, b) (fabs(a-b) < EPS)
#define fcout(n) cout << fixed << setprecision(n)
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

// pointの回転(原点中心).degreeは度数
point rotate(point p, double theta){
    double rad = DEGtoRAD(theta);
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

// pointの回転(point c中心).degreeは度数
point rotateAroundPoint(point p, point c, double theta){
    point tmp(p.x - c.x, p.y - c.y);
    point rot = rotate(tmp, theta);
    return point(rot.x + c.x, rot.y + c.y);
}
/* -------------------------------------------------- */

// 直線 ax+by+c = 0
struct line{
    double a, b, c;
};

// 2つのpointをlineに変換
void pointsToLine(point p1, point p2, line &l){
    // 2つのpointが成すlineがy軸に平行な場合
    if(fabs(p1.x - p2.x) < EPS){
        l.a = 1.0, l.b = 0.0, l.c = -p1.x;
    }else{
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

// 2つのlineの平行判定
bool areParallel(line l1, line l2){
    return Equals(l1.a,l2.a) && Equals(l2.a,l2.b);
}

// 2つのlineの一致判定
bool areSame(line l1, line l2){
    return areParallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}

// 2つのlineの交差判定(未確認)
bool areIntersect(line l1, line l2, point &p){
    if(areParallel(l1, l2)) return false;

    p.x = (l2.b * l1.c - l1.b * l2.c) / 
          (l2.a * l1.b - l1.a * l2.b);

    // l1.bが0(EPS未満)の場合,l1はy軸に平行
    if(fabs(l1.b) < EPS){
        p.y = -(l1.a * p.x + l1.c);
    }else{
        p.y = -(l2.a * p.x + l2.c);
    }

    return true;
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

double abs(vec v){
    return sqrt(norm_sq(v));
}

// point p と point a,bが成す直線との距離
// point cにはpをabに射影したpointが渡される
// c = a + u * ab(未確認)
double distToLine(point p, point a, point b, point &c){
    vec ap = toVec(a, p);
    vec ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, ab*u);
    return dist(p, c);
}

// point a,bがなす直線に関してpoint pと線対称な点を返す
point reflect(point p, point a, point b){
    point intersec;
    distToLine(p, a, b, intersec);
    point x = (intersec - p)*2.0;
    return p+x;
}

int main(){
    double x1, y1, x2, y2, x, y;
    int q;

    cin >> x1 >> y1 >> x2 >> y2;
    point a(x1, y1), b(x2, y2);

    cin >> q;
    while(q-- > 0){
        cin >> x >> y;
        point p(x,y);
        point ans = reflect(p, a, b);
        fcout(10) << ans.x << " " << ans.y << endl;
    }

    return 0;
}