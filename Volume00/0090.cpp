#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const double EPS = 1e-7;

struct Point{
    double x, y;
    Point operator + (Point obj){
        return Point({(x+obj.x), (y+obj.y)});
    }
    Point operator / (double d){
        return Point({x/d, y/d});
    }
    Point operator * (double d){
        return Point({x*d, y*d});
    }
    Point operator - (Point obj){
        return Point({(x-obj.x), (y-obj.y)});
    }
    double norm(){
        return sqrt(x*x + y*y);
    }
    void normalize(){
        double t = norm();
        x /= t, y /= t;
    }
};

double dist(Point a, Point b){
    return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));
}

vector<Point> v, is;

void getIntersect(int i, int j){
    Point a = v[i], b = v[j];
    Point mid = (a+b)/2.0;
    Point s = mid-a;
    double k = s.norm();
    s.normalize();
    swap(s.x, s.y); s.x *= -1;
    double l = sqrt(1*1 - k*k);
    is.push_back(mid+s*l);
    is.push_back(mid-s*l);
}

int main(){
    int n;
    while(scanf("%d", &n), n){
        v.resize(n);
        is.clear();
        for(int i = 0; i < n; i++){
            scanf("%lf,%lf\n", &v[i].x, &v[i].y);
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(dist(v[i], v[j]) > 2.0)  continue;
                getIntersect(i, j);
            }
        }
        int ans = 1;
        for(Point p : is){
            int tmp = 0;
            for(int j = 0; j < n; j++){
                if(dist(p, v[j]) < 1.0+EPS)    tmp++;
            }
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}