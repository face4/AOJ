#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

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

/* -------------------------------------------------- */

typedef point vec;

// 2つのpoint a,b をvec a->b に変換
vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

point translate(point p, vec v){
    return point(p.x + v.x, p.y + v.y);
}

double dot(vec v1, vec v2){
    return v1.x * v2.x + v1.y * v2.y;
}

double norm_sq(vec v){
    return v.x * v.x + v.y * v.y;
}

double abs(vec v){
    return sqrt(norm_sq(v));
}

double distToLine(point p, point a, point b, point &c){
    vec ap = toVec(a, p);
    vec ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, ab*u);
    return dist(p, c);
}

// point p と point a,bが成す線分との距離
// distToLineに場合分けを加える
// point cにはpoint pに最も近い線分ab上のpointが渡される
double distToLineSegment(point p, point a, point b, point &c){
    vec ap = toVec(a, p);
    vec ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);

    // uが0より小さいならば,point pから直線abに下した垂線
    // は線分abと交わらず,垂線の足はbよりaの方が近い.
    // uが1より大きいならば同様に交わらず,垂線の足はaよりbの方が近い.
    if(u < 0.0){
        c = point(a.x , a.y);
        return dist(p, a);
    }else if(u > 1.0){
        c = point(b.x , b.y);
        return dist(p, b);
    }

    // point pの線分abへの射影が線分ab上に収まる
    return distToLine(p, a, b, c);
}
int main(){
    int n;
    while(cin >> n, n){
        vector<point> v(n);
        vector<double> r(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].x >> v[i].y >> r[i];
        }
        int m;
        cin >> m;
        while(m-- > 0){
            double a, b, c, d;
            cin >> a >> b >> c >> d;
            point s({a,b}), t({c,d}), g;
            bool safe = false;
            for(int i = 0; i < n; i++){
                if(distToLineSegment(v[i], s, t, g) <= r[i]){
                    if(dist(s,v[i]) <= r[i] && dist(t,v[i]) <= r[i]){
                        // do nothing.
                    }else{
                        safe = true;
                    }
                }
            }
            cout << (!safe ? "Danger" : "Safe") << endl;
        }
    }
    return 0;
}