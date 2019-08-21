#include<iostream>
#include<cmath>
using namespace std;
#define equals(a, b) (fabs(a-b) < 1e-3)

struct Point{
    double x, y, z;
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    Point() {}
};

double dist(Point a, Point b){
    return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0)+pow(a.z-b.z,2.0));
}

int main(){
    int q;
    cin >> q;
    while(q-- > 0){
        double a[3];
        cin >> a[1] >> a[2] >> a[0];
        int n;
        cin >> n;
        Point p[n];
        for(int i = 0; i < n; i++)  cin >> p[i].x >> p[i].y >> p[i].z;
        int f, g, h;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i==j)     continue;
                for(int k = 0; k < n; k++){
                    if(i==k || j==k)    continue;
                    double b[3];
                    b[0] = dist(p[i], p[j]);
                    b[1] = dist(p[j], p[k]);
                    b[2] = dist(p[k], p[i]);
                    bool valid = true;
                    for(int l = 0; l < 3; l++)  valid &= equals(b[0]/a[0], b[l]/a[l]);
                    if(valid){
                        f = i, g = j, h = k;
                    }
                }
            }
        }
        cout << f+1 << " " << g+1 << " " << h+1 << endl;
    }
    return 0;
}