#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

struct Point;
typedef Point Vector;
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
Point project(Segment s, Point p);
Point reflect(Segment s, Point p);

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


struct Segment{
    Point p1, p2;
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

Point project(Segment s, Point p){
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}

Point reflect(Segment s, Point p){
    return p + (project(s, p) - p) * 2.0;
}



int main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    Point p0(a, b), p1(c, d);

    int q;
    cin >> q;

    while(q-- > 0){
        double x, y;
        cin >> x >> y;
        int res = ccw(p0, p1, Point(x,y));
        if(res == 1)    cout << "COUNTER_CLOCKWISE" << endl;
        if(res == -1)   cout << "CLOCKWISE" << endl;
        if(res == 2)    cout << "ONLINE_BACK" << endl;
        if(res == -2)   cout << "ONLINE_FRONT" << endl;
        if(res == 0)    cout << "ON_SEGMENT" << endl;
    }
    return 0;
}
