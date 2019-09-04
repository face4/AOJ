#include<iostream>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[2] = {0,1};
int dj[2] = {1,0};

int h, w, n;

bool check(vector<string> v){
    // まず落下
    for(int i = h-2; i >= 0; i--){
        for(int j = 0; j < w; j++){
            if(v[i][j] == '.')  continue;
            int cp = i;
            while(cp+1 < h && v[cp+1][j] == '.'){
                swap(v[cp][j], v[cp+1][j]);
                cp++;
            }
        }
    }
    bool update = true;
    while(update){
        update = false;
        vector<vector<bool>> erase(h, vector<bool>(w, 0));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(v[i][j] == '.')  continue;
                for(int k = 0; k < 2; k++){
                    int ni = i+di[k], nj = j+dj[k], cnt = 1;
                    while(inRange(ni,0,h)&&inRange(nj,0,w)&&v[ni][nj]==v[i][j]){
                        ni += di[k], nj += dj[k], cnt++;
                    }
                    if(cnt < n) continue;
                    update = true;
                    do{
                        ni -= di[k], nj -= dj[k];
                        erase[ni][nj] = true;
                    }while(ni != i || nj != j);
                }
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(erase[i][j]) v[i][j] = '.';
            }
        }    
        for(int i = h-2; i >= 0; i--){
            for(int j = 0; j < w; j++){
                if(v[i][j] == '.')  continue;
                int cp = i;
                while(cp+1 < h && v[cp+1][j] == '.'){
                    update = true;
                    swap(v[cp][j], v[cp+1][j]);
                    cp++;
                }
            }
        }
    }
    bool ret = true;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ret &= v[i][j]=='.';
        }
    }
    return ret;
}

int main(){
    cin >> h >> w >> n;
    vector<string> v(h);
    for(int i = 0; i < h; i++)  cin >> v[i];
    bool valid = false;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int ni = i+di[0], nj = j+dj[0];
            if(!inRange(ni,0,h) || !inRange(nj,0,w) || v[i][j]==v[ni][nj]){
                continue;
            }
            swap(v[i][j], v[ni][nj]);
            valid |= check(v);
            swap(v[i][j], v[ni][nj]);
        }
    }
    cout << (valid ? "YES" : "NO") << endl;
    return 0;
}