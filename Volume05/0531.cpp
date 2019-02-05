// 座圧debut
// よくわからない.
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define inRange(x,a,b) (a <= x && x <= b)
#define N 1000
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int w, h, n;
int X1[N], X2[N], Y1[N], Y2[N];

// 座圧後の配列には線分の両端点の+1,0,-1の3点が残る可能性がある(?)
// よって2*3で6倍
bool mat[6*N][6*N];

int compress(int *x1, int *x2, int width){
    vector<int> xs;

    for(int i = 0; i < n; i++){
        for(int d = -1; d <= 1; d++){
            int dx1 = x1[i]+d, dx2 = x2[i]+d;
            if(inRange(dx1, 0, width))  xs.push_back(dx1);
            if(inRange(dx2, 0, width))  xs.push_back(dx2);
        }
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    for(int i = 0; i < n; i++){
        x1[i] = distance(xs.begin(), lower_bound(xs.begin(), xs.end(), x1[i]));
        x2[i] = distance(xs.begin(), lower_bound(xs.begin(), xs.end(), x2[i]));
    }

    return xs.size()-1;
}

int main(){
    while(cin >> w >> h, w+h){
        cin >> n;
        
        for(int i = 0; i < n; i++){
            cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        }
        
        w = compress(X1, X2, w);
        h = compress(Y1, Y2, h);

        memset(mat, 0, sizeof(mat));

        for(int i = 0; i < n; i++){
            for(int y = Y1[i]; y < Y2[i]; y++){
                for(int x = X1[i]; x < X2[i]; x++){
                    mat[y][x] = true;
                }
            }
        }

        // for(int i = 0; i < h; i++){
        //     for(int j = 0; j < w; j++){
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int ans = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(mat[i][j])   continue;

                ans++;
                queue<pair<int,int>> q;
                q.push({i,j});

                while(!q.empty()){
                    pair<int,int> p = q.front();    q.pop();
                    int y = p.first, x = p.second;
                    if(mat[y][x]) continue;
                    mat[y][x] = true;
                    for(int k = 0; k < 4; k++){
                        int ny = y + di[k], nx = x + dj[k];
                        if(!inRange(ny, 0, h-1) || !inRange(nx, 0, w-1) || mat[ny][nx])    continue;
                        q.push({ny,nx});
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}