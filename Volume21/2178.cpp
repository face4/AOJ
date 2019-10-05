#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int n;
    while(cin >> n, n){
        set<pair<int,int>> points;
        map<pair<int,int>,pair<int,int>> futon;
        for(int i = 0; i < n; i++){
            int x, y;
            char c;
            cin >> x >> y >> c;
            points.insert({x, y});
            int nx = x, ny = y;
            (c == 'x' ? nx : ny)++;
            points.insert({nx, ny});
            futon[{x,y}] = {nx,ny};
            futon[{nx,ny}] = {x,y};
        }
        map<pair<int,int>,int> color;
        bool valid = true;
        for(pair<int,int> p : points){
            if(!valid)  break;
            if(color.count(p))    continue;
            queue<pair<int,int>> paint;
            paint.push(p);
            color[p] = 1;
            while(!paint.empty()){
                pair<int,int> now = paint.front(); paint.pop();
                for(int k = 0; k < 4; k++){
                    pair<int,int> next = now;
                    next.first += di[k], next.second += dj[k];
                    if(points.count(next) == 0)   continue;
                    int nowcolor = color[now], nextcolor = color[next];
                    if(next == futon[now]){
                        if(nextcolor == 0){
                            color[next] = -nowcolor;
                            paint.push(next);
                        }else if(nextcolor == nowcolor){
                            valid = false;
                            break;
                        }else{
                            // futon[now] has already colored correctly
                        }
                    }else{
                        if(nextcolor){
                            if(nextcolor != nowcolor)   valid = false;
                        }else{
                            color[next] = nowcolor;
                            paint.push(next);
                        }
                    }
                }
            }
        }
        cout << (valid ? "Yes" : "No") << endl;
    }
    return 0;
}