// 解説を読んだ
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const double INF = 1e6;
const double EPS = 1e-8;
#define same(a, b) (abs(a-b) < EPS)

double a, b, c, d;

double fx(double x){
    return a*x*x*x+b*x*x+c*x+d;
}

bool binary(double l, double r, double &v){
    if(same(fx(l), 0)){
        v = l;
        return true;
    }
    if(same(fx(r), 0)){
        v = r;
        return true;
    }
    if(fx(l)*fx(r) > 0) return false;
    int loop = 200;
    while(loop-- > 0){
        double mid = (l+r)/2;
        double val = fx(mid);
        if(val*fx(l) > 0)   l = mid;
        else                r = mid;
    }
    if(same(fx(l),0)){
        v = l;
        return true;
    }
    if(same(fx(r),0)){
        v = r;
        return true;
    }
    return false;
}


int main(){
    int q;
    cin >> q;
    while(q-- > 0){
        int p = 0, m = 0;
        auto judge = [&](double val){
            if(same(val,0)) return;
            if(val < 0) m++;
            if(val > 0) p++;
        };
        cin >> a >> b >> c >> d;
        double det = b*b-3*a*c;
        if(det >= 0){
            double l = (-b-sqrt(b*b-3*a*c))/(3*a);
            double r = (-b+sqrt(b*b-3*a*c))/(3*a);
            if(l > r)   swap(l, r);
            double tmp;
            if(binary(-INF, l, tmp))    judge(tmp);
            if(binary(l, r, tmp))       judge(tmp);
            if(binary(r, INF, tmp))     judge(tmp);
        }else{
            double tmp;
            if(binary(-INF, INF, tmp))  judge(tmp);
        }
        printf("%d %d\n", p, m);
    }
    return 0;
}