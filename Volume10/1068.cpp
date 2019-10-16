#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;

const int INF = INT_MAX;

int node[9000000];
int h, w;

int enc(int i, int j){
    return i*(2*w-1)+j;
}

void init(int hsiz, int wsiz, vector<vector<int>> &v){
    for(int i = 0; i < hsiz; i++){
        for(int j = 0; j < wsiz; j++){
            node[enc(h-1+i,w-1+j)] = v[i][j];
        }
    }
    for(int i = 2*h-2; i > h-2; i--){
        for(int j = w-2; j >= 0; j--){
            node[enc(i,j)] = min(node[enc(i,2*j+1)], node[enc(i,2*j+2)]);
        }
    }
    for(int i = h-2; i >= 0; i--){
        for(int j = 0; j < 2*w-1; j++){
            node[enc(i,j)] = min(node[enc(2*i+1,j)], node[enc(2*i+2,j)]);
        }
    }
}

void seg2d(vector<vector<int>> &v){
    int hsiz = v.size(), wsiz = v[0].size();
    h = w = 1;
    while(h < hsiz)    h *= 2;
    while(w < wsiz)    w *= 2;
    int lim = enc(2*h, 2*w);
    for(int i = 0; i < lim; i++)    node[i] = INF;
    init(hsiz, wsiz, v);
}

int query_w(int lj, int rj, int l, int r, int i, int k){
    if(rj <= l || r <= lj)  return INF;
    if(lj <= l && r <= rj)  return node[enc(i,k)];
    int lx = query_w(lj,rj,l,(l+r)/2,i,2*k+1);
    int rx = query_w(lj,rj,(l+r)/2,r,i,2*k+2);
    return min(lx, rx);
}

int query_h(int li, int lj, int ri, int rj, int l, int r, int k){
    if(ri <= l || r <= li)  return INF;
    if(li <= l && r <= ri)  return query_w(lj, rj, 0, w, k, 0);
    int lx = query_h(li,lj,ri,rj,l,(l+r)/2,2*k+1);
    int rx = query_h(li,lj,ri,rj,(l+r)/2,r,2*k+2);
    return min(lx, rx);
}

int query(int li, int lj, int ri, int rj){
    return query_h(li, lj, ri, rj, 0, h, 0);
}

int main(){
    int r, c, q;
    while(cin >> r >> c >> q, r+c+q){
        vector<vector<int>> v(r, vector<int>(c));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> v[i][j];
            }
        }
        seg2d(v);
        while(q-- > 0){
            int li, lj, ri, rj;
            cin >> li >> lj >> ri >> rj;
            cout << query(li,lj,ri+1,rj+1) << endl;
        }
    }
    return 0;
}
