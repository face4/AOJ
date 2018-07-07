#include<iostream>
#include<cmath>
using namespace std;

// 度->ラジアンの変換
#define DEGtoRAD(X) (X*PI)/180.0
// 円周率
const double PI = 2 * acos(0.0);
// 許容誤差.問題によって変える
const double EPS = 1e-9;

struct point{
    double x, y;
    point(){ x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}

    // 不等号のオーバーロード.x座標,y座標で昇順ソート
    bool operator < (const point other) const{
        if(fabs(x - other.x) > EPS)
            return x < other.x;
        else
            return y < other.y;
    }

    // 等号のオーバーロード.
    bool operator == (const point other) const{
        return fabs(x - other.x) < EPS &&
                fabs(y - other.y) < EPS;
    }
};

// ベクトル
struct vec{
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

// 2つのpoint a,b をvec a->b に変換
vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

// vecの外積
double cross(vec v1, vec v2){
    return v1.x * v2.y - v1.y * v2.x;
}

// point rが3つのpointからなる三角形の内部に存在するかどうかの判定
// 三角形の内側に点があるとき、外積によるベクトルは同じ方向を向くことを利用
// -1...内側 0...辺上 1...外側
int inTriangle(point r, point a, point b, point c){
    double c1 = cross(toVec(a,b), toVec(b,r));
    double c2 = cross(toVec(b,c), toVec(c,r));
    double c3 = cross(toVec(c,a), toVec(a,r));

    if(c1 == 0 || c2 == 0 || c3 == 0)           return 0;
    else if( (c1 > 0 && c2 > 0 && c3 > 0) || 
        (c1 < 0 && c2 < 0 && c3 < 0)        )   return -1;
    else                                        return 1;
}

int main(){
    int n;
    cin >> n;

    double input[10];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cin >> input[j];
            input[j] += 1000.0;
        }

        point p1(input[0], input[1]);
        point p2(input[2], input[3]);
        point p3(input[4], input[5]);
        point k(input[6], input[7]);
        point s(input[8], input[9]);

        int kengyu = inTriangle(k, p1, p2, p3);
        int orihime = inTriangle(s, p1, p2, p3);

        if(kengyu * orihime == -1)  cout << "OK" << endl;
        else                        cout << "NG" << endl;

    }
    return 0;
}