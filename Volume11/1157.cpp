#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cassert>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

struct Point;
typedef Point Vector;
typedef vector<Point> Polygon;
struct Circle;
struct Segment;
typedef Segment Line;
double norm(Point a);
double abs(Point a);
double dot(Vector a, Vector b);
double cross(Vector a, Vector b);
double getDistance(Point a, Point b);
double getDistanceLP(Line l, Point p);
double getDistanceSP(Segment s, Point p);
double getDistance(Segment s1, Segment s2);
bool isOrthogonal(Vector a, Vector b);
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2);
bool isOrthogonal(Segment s1, Segment s2);
bool isParallel(Vector a, Vector b);
bool isParallel(Point a1, Point a2, Point b1, Point b2);
bool isParallel(Segment s1, Segment s2);
int ccw(Point p0, Point p1, Point p2);
bool intersect(Point p1, Point p2, Point p3, Point p4);
bool intersect(Segment s1, Segment s2);
bool intersect(Circle c, Line l); // 誤差の検証をしていない
bool intersect(Circle c1, Circle c2); // 誤差の検証をしていない

Point project(Segment s, Point p);
Point reflect(Segment s, Point p);
Point getCrossPoint(Segment s1, Segment s2);
pair<Point,Point> getCrossPoints(Circle c, Line l);
pair<Point,Point> getCrossPoints(Circle c1, Circle c2); // 誤差の検証をしていない
pair<Point,Point> getContactPoints(Circle c, Point p); // 接点 点は円の外部

double area(Polygon g); // convexでなくてもよい. absを消せば符号付き面積
bool isConvex(Polygon g); // O(n^2) 線形時間アルゴリズムが存在するらしい
int contains(Polygon g, Point p);

double arg(Vector p);   // 偏角
Vector polar(double a, double r); // 極座標系->ベクトル

Polygon andrewScan(Polygon g); // 凸包の辺上の点も含めたければ!=CLOCKWISEを==COUNTER_CLOCKWISEに
double convexDiameter(Polygon g); // gはconvex 


struct Point{
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator + (Point p){ return Point(x+p.x, y+p.y); }
    Point operator - (Point p){ return Point(x-p.x, y-p.y); }
    Point operator * (double a){ return Point(a*x, a*y); }
    Point operator / (double a){ return Point(x/a, y/a); }

    double abs() { return sqrt(norm()); }
    double norm() { return x*x + y*y; }

    bool operator < (const Point &p) const{
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const{
        return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};

typedef Point Vector;
typedef vector<Point> Polygon;

struct Circle{
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

struct Segment{
    Point p1, p2;
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};

typedef Segment Line;


double norm(Point a){
    return a.x * a.x + a.y * a.y;
}

double abs(Point a){
    return sqrt(norm(a));
}

double dot(Vector a, Vector b){
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b){
    return a.x * b.y - a.y * b.x;
}

double getDistance(Point a, Point b){
    return abs(a - b);
}

double getDistanceLP(Line l, Point p){
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double getDistanceSP(Segment s, Point p){
    if(dot(s.p2-s.p1, p-s.p1) < 0.0)    return abs(p-s.p1);
    if(dot(s.p1-s.p2, p-s.p2) < 0.0)    return abs(p-s.p2);
    return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2){
    if(intersect(s1, s2))   return 0.0;
    return min({getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2), 
                getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)});
}


bool isOrthogonal(Vector a, Vector b){
    return equals(dot(a, b), 0.0);
}
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2){
    return isOrthogonal(a1-a2, b1-b2);
}
bool isOrthogonal(Segment s1, Segment s2){
    return equals(dot(s1.p2-s1.p1, s2.p2-s2.p1), 0.0);
}
bool isParallel(Vector a, Vector b){
    return equals(cross(a, b), 0.0);
}
bool isParallel(Point a1, Point a2, Point b1, Point b2){
    return isParallel(a1-a2, b1-b2);
}
bool isParallel(Segment s1, Segment s2){
    return equals(cross(s1.p2-s1.p1, s2.p2-s2.p1), 0.0);
}


static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;   // p2->p0->p1
static const int ONLINE_FRONT = -2; // p0->p1->p2
static const int ON_SEGMENT = 0;    // p0->p2->p1
int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS)   return COUNTER_CLOCKWISE;
    if(cross(a, b) < -EPS)  return CLOCKWISE;
    if(dot(a, b) < -EPS)    return ONLINE_BACK;
    if(norm(a) < norm(b))   return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersect(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersect(Segment s1, Segment s2){
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
bool intersect(Circle c, Line l){
    return getDistanceLP(l, c.c) < c.r+EPS;
}
bool intersect(Circle c1, Circle c2){
    return abs(c1.r-c2.r) <= getDistance(c1.c, c2.c) && getDistance(c1.c, c2.c) < c1.r+c2.r+EPS;
}

Point project(Segment s, Point p){
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}

Point reflect(Segment s, Point p){
    return p + (project(s, p) - p) * 2.0;
}

Point getCrossPoint(Segment s1, Segment s2){
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1-s2.p1));
    double d2 = abs(cross(base, s1.p2-s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

pair<Point,Point> getCrossPoints(Circle c, Line l){
    assert(intersect(c, l));
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
    double base = sqrt(c.r * c.r - norm(pr - c.c));
    return make_pair(pr + e*base, pr - e*base);
}

pair<Point,Point> getCrossPoints(Circle c1, Circle c2){
    assert(intersect(c1, c2));
    double d = abs(c1.c - c2.c);
    double a = acos( (c1.r*c1.r + d*d - c2.r*c2.r)/(2*c1.r*d) );
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t+a), c1.c + polar(c1.r, t-a));
}

pair<Point,Point> getContactPoints(Circle c, Point p){
    assert(c.r < getDistance(c.c, p));
    double d = getDistance(c.c, p);
    return getCrossPoints(c, Circle(p, sqrt(d*d-c.r*c.r)));
}

double area(Polygon g){
    if(g.size() < 3)    return 0;
    int n = g.size();
    Point o(0.0, 0.0);
    double s = 0.0;
    for(int i = 0; i < n; i++)  s += cross(g[i]-o, g[(i+1)%n]-o);
    return abs(s) / 2.0;
}

bool isConvex(Polygon g){
    bool ret = true;
    int n = g.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(cross(g[i]-g[(i+n-1)%n], g[j]-g[(i+n-1)%n]) < -EPS || cross(g[(i+1)%n]-g[i], g[j]-g[i]) < -EPS){
                ret = false;
            }
        }
    }
    return ret;
}

static const int IN = 2;
static const int ON = 1;
static const int OUT = 0;
int contains(Polygon g, Point p){
    int n = g.size();
    bool x = false;
    for(int i = 0; i < n; i++){
        Point a = g[i] - p, b = g[(i+1)%n] - p;
        if(abs(cross(a, b)) < EPS && dot(a, b) < EPS)   return ON;
        if(a.y > b.y)   swap(a, b);
        if(a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
    }
    return x ? IN : OUT;
}


double arg(Vector p){
    return atan2(p.y, p.x);
}

Vector polar(double a, double r){
    return Point(a * cos(r), a * sin(r));
}


Polygon andrewScan(Polygon g){
    Polygon u, l;
    if(g.size() < 3)    return g;
    sort(g.begin(), g.end());
    u.push_back(g[0]);
    u.push_back(g[1]);
    l.push_back(g[g.size()-1]);
    l.push_back(g[g.size()-2]);

    // upper
    for(int i = 2; i < g.size(); i++){
        for(int n = u.size(); n >= 2 && ccw(u[n-2], u[n-1], g[i]) != CLOCKWISE; n--){
            u.pop_back();
        }
        u.push_back(g[i]);
    }

    // lower
    for(int i = g.size()-3; i >= 0; i--){
        for(int n = l.size(); n >= 2 && ccw(l[n-2], l[n-1], g[i]) != CLOCKWISE; n--){
            l.pop_back();
        }
        l.push_back(g[i]);
    }

    reverse(l.begin(), l.end());
    for(int i = u.size()-2; i >= 1; i--)    l.push_back(u[i]);

    return l;
}

double convexDiameter(Polygon g){
    double d = 0.0;
    int n = g.size();
    int is = 0, js = 0;
    for(int i = 1; i < n; i++){
        if(g[i].y > g[is].y)    is = i;
        if(g[i].y < g[js].y)    js = i;
    }
    d = getDistance(g[is], g[js]);

    int i = is, j = js, maxi = is, maxj = js;
    do{
        if(cross(g[(i+1)%n]-g[i], g[(j+1)%n]-g[j]) >= 0.0)  j = (j+1)%n;
        else    i = (i+1)%n;
        if(getDistance(g[i], g[j]) > d){
            d = getDistance(g[i], g[j]);
            maxi = i, maxj = j;
        }
    }while(i != is || j != js);

    return d; // farthest pair is (maxi, maxj).
}

int main(){
    int n;
    while(cin >> n, n){
        double ans = 1000;
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        Segment s(Point(sx,sy), Point(ex,ey));
        for(int i = 0; i < n; i++){
            int x[2], y[2], h;
            cin >> x[0] >> y[0] >> x[1] >> y[1] >> h;
            if(x[0] <= min(sx,ex) && max(sx,ex) <= x[1] && y[0] <= min(sy,ey) && max(sy,ey) <= y[1])    ans = 0;
            Point p[4] = {Point(x[0],y[0]), Point(x[0],y[1]), Point(x[1],y[1]), Point(x[1],y[0])};
            for(int j = 0; j < 4; j++){
                double d = getDistance(s, Segment(p[j], p[(j+1)%4]));
                if(d <= h)  ans = min(ans, d);
                else        ans = min(ans, (d*d+h*h)/2/h);
                if(intersect(s, Segment(p[j], p[(j+1)%4]))) ans = 0;
            }
        }
        cout << fixed << setprecision(12) << ans << endl;
    }
    return 0;
}
