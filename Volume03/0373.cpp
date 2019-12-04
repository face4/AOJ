#include<iostream>
#include<vector>
using namespace std;

int main(){
    int w, h;
    cin >> w >> h;
    int mat[h][w], sum = 0;
    vector<int> one, zero;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(i==0){
                if(mat[i][j]==0)    zero.push_back(j);
                else                one.push_back(j);
            }
        }
    }
    bool valid = false;
    if(zero.size() == (w+1)/2){
        bool ng = false;
        vector<int> ind;
        for(int i = 0; i < zero.size(); i++){
            ind.push_back(zero[i]);
            if(i < one.size())  ind.push_back(one[i]);
        }
        int z = 1;
        for(int i = 1; i < h; i++){
            int bef = mat[i][ind[0]];
            bool ok = true;
            for(int j = 1; j < w; j++){
                ok &= bef != mat[i][ind[j]];
                bef = mat[i][ind[j]];
            }
            if(!ok){
                ng = true;
                break;
            }
            if(ok && mat[i][ind[0]]==0) z++;
        }
        if(!ng && (z == h/2 || z == (h+1)/2))    valid = true;
    }
    if(one.size() == (w+1)/2){
        bool ng = false;
        vector<int> ind;
        for(int i = 0; i < one.size(); i++){
            ind.push_back(one[i]);
            if(i < zero.size())  ind.push_back(zero[i]);
        }
        int o = 1;
        for(int i = 1; i < h; i++){
            int bef = mat[i][ind[0]];
            bool ok = true;
            for(int j = 1; j < w; j++){
                ok &= bef != mat[i][ind[j]];
                bef = mat[i][ind[j]];
            }
            if(!ok){
                ng = true;
                break;
            }
            if(ok && mat[i][ind[0]]==1) o++;
        }
        if(!ng && (o == h/2 || o == (h+1)/2))    valid = true;
    }
    cout << (valid ? "yes" : "no") << endl;
    return 0;
}