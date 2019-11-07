#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

#define in(x) (0 <= x && x <= 1)

struct Point{
    double x, y, z;
    Point(double x, double y, double z) : x(x),y(y),z(z) {}
    double norm(){
        return x*x+y*y+z*z;
    }
    Point operator* (double d){
        return Point{x*d, y*d, z*d};
    }
    Point operator- (const Point& other){
        return Point{x-other.x, y-other.y, z-other.z};
    }
    double cross(const Point& other){
        return x*other.x+y*other.y+z*other.z;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<Point> vp;
    vector<double> vr;
    vector<ll> vs;
    for(int i = 0; i < n; i++){
        double x, y, z, r;
        ll l;
        cin >> x >> y >> z >> r >> l;
        vp.push_back(Point{x,y,z});
        vr.push_back(r);
        vs.push_back(l);
    }
    while(q-- > 0){
        double sx, sy, sz, tx, ty, tz;
        cin >> sx >> sy >> sz >> tx >> ty >> tz;
        Point P{sx,sy,sz}, Q{tx,ty,tz};
        Point D = Q-P;
        double a = D.norm();
        ll ans = 0;
        for(int i = 0; i < n; i++){
            double b = 2*P.cross(D)-2*D.cross(vp[i]);
            double c = P.norm()+vp[i].norm()-2*P.cross(vp[i])-vr[i]*vr[i];
            if(b*b-4*a*c < 0)  continue;
            if(in((-b+sqrt(b*b-4*a*c))/2/a) || in((-b-sqrt(b*b-4*a*c))/2/a))    ans += vs[i];
        }
        cout << ans << endl;
    }
    return 0;
}
