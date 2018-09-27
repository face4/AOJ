#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define inRange(x,a,b) (a <= x && x <= b)

struct Node{
    int location, p, l, r;
    Node() {}
};

struct Point{
    int id, x, y;
    Point() {}
    Point(int id, int x, int y) : id(id), x(x), y(y) {}
    bool operator<(const Point other) const{
        return id < other.id;
    }
    void print(){
        printf("%d\n", id);
    }
};

static const int MAX = 1000000;
static const int NIL = -1;

int N;
Point P[MAX];
Node T[MAX];
int np;
vector<Point> ans;

bool lessX(Point p1, Point p2)  {return p1.x < p2.x;}
bool lessY(Point p1, Point p2)  {return p1.y < p2.y;}

int makeKDTree(int l, int r, int depth){
    if(!(l < r))    return NIL;
    int mid = (l + r) / 2;
    int t = np++;
    if(depth % 2 == 0){
        sort(P+l, P+r, lessX);
    }else{
        sort(P+l, P+r, lessY);
    }
    T[t].location = mid;
    T[t].l = makeKDTree(l, mid, depth+1);
    T[t].r = makeKDTree(mid+1, r, depth+1);

    return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth){
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;
    if(inRange(x, sx, tx) && inRange(y, sy, ty)){
        ans.push_back(P[T[v].location]);
    }

    if(depth % 2 == 0){
        if(T[v].l != NIL && sx <= x)
            find(T[v].l, sx, tx, sy, ty, depth+1);
        if(T[v].r != NIL && x <= tx)
            find(T[v].r, sx, tx, sy, ty, depth+1);
    }else{
        if(T[v].l != NIL && sy <= y)
            find(T[v].l, sx, tx, sy, ty, depth+1);
        if(T[v].r != NIL && y <= ty)
            find(T[v].r, sx, tx, sy, ty, depth+1);
    }
}

int main(){
    scanf("%d", &N);
    int x, y;
    for(int i = 0; i < N; i++){
        scanf("%d %d", &x, &y);
        P[i] = Point(i, x, y);
        T[i].l = T[i].r = T[i].p = NIL;
    }

    np = 0;
    int root = makeKDTree(0, N, 0);

    int q;
    scanf("%d", &q);
    int sx, tx, sy, ty;
    for(int i = 0; i < q; i++){
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        ans.clear();
        find(root, sx, tx, sy, ty, 0);
        sort(ans.begin(), ans.end());
        for(int j = 0; j < ans.size(); j++){
            ans[j].print();
        }
        printf("\n");
    }
    return 0;
}
