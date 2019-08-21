#include<iostream>
using namespace std;
typedef unsigned long long ull;

const ull B1 = 9973;
const ull B2 = 1000000007;

int main(){
    int h, w;
    cin >> h >> w;
    char a[h][w];
    for(int i = 0; i < h; i++)  for(int j = 0; j < w; j++)  cin >> a[i][j];
    int r, c;
    cin >> r >> c;
    char b[r][c];
    for(int i = 0; i < r; i++)  for(int j = 0; j < c; j++)  cin >> b[i][j];
    
    ull d[h][w-c+1], hash[h-r+1][w-c+1];
    ull t1 = 1;
    for(int i = 0; i < c; i++)  t1 *= B1;
    for(int i = 0; i < h; i++){
        ull tmp = 0;
        for(int j = 0; j < c; j++){
            tmp = tmp * B1 + a[i][j];
        }
        for(int j = 0; j+c <= w; j++){
            d[i][j] = tmp;
            if(j+c < w) tmp = tmp*B1 + a[i][j+c] - a[i][j]*t1;
        }
    }
    ull t2 = 1;
    for(int i = 0; i < r; i++)  t2 *= B2;
    for(int j = 0; j < w-c+1; j++){
        ull tmp = 0;
        for(int i = 0; i < r; i++){
            tmp = tmp * B2 + d[i][j];
        }
        for(int i = 0; i+r <= h; i++){
            hash[i][j] = tmp;
            if(i+r < h) tmp = tmp * B2 + d[i+r][j] - d[i][j]*t2;
        }
    }

    ull pat[r];
    for(int i = 0; i < r; i++){
        pat[i] = 0;
        for(int j = 0; j < c; j++){
            pat[i] = pat[i] * B1 + b[i][j];
        }
    }
    ull x = 0;
    for(int i = 0; i < r; i++){
        x = x * B2 + pat[i];
    }

    for(int i = 0; i < h-r+1; i++){
        for(int j = 0; j < w-c+1; j++){
            if(hash[i][j] == x){
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}