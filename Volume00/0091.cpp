#include<iostream>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

struct hand{
    int i, j, k;
};

vector<hand> ans;

int mat[10][10];
int n;
int mov[3][5][2] = {
    {{0,0},{-1,1},{0,0},{1,0},{1,0}} , 
    {{0,2},{0,2},{0,2},{1,0},{1,0}} , 
    {{0,0},{-1,1},{-2,2},{-1,1},{0,0}}
};
int pos[3][2] = {{1,0}, {1,1}, {2,0}};

void paint(int pi, int pj, int k, int d){
    for(int i = 0; i < 5; i++){
        for(int j = mov[k][i][0]; j <= mov[k][i][1]; j++){
            mat[pi+i][pj+j] += d;
        }
    }
}

void dfs(int pi, int pj, int cur){
    if(cur == n){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(mat[i][j] != 0)  return;
            }
        }
        // ok.
        for(hand t : ans)   cout << t.j << " " << t.i << " " << t.k << endl;
        exit(0);
    }

    if(mat[pi][pj] == 0){
        dfs(pi+(pj==9), (pj+1)%10, cur);
    }else{
        for(int k = 0; k < 3; k++){
            bool valid = true;
            for(int i = 0; i < 5; i++){
                for(int j = mov[k][i][0]; j <= mov[k][i][1]; j++){
                    valid &= inRange(pi+i,0,10)&&inRange(pj+j,0,10)&&(mat[pi+i][pj+j] >= 1);
                }
            }
            if(!valid)  continue;

            paint(pi, pj, k, -1);   // erase
            ans.push_back(hand({pi+pos[k][0], pj+pos[k][1], k+1}));
            dfs(pi, pj, cur+1);
            ans.pop_back();
            paint(pi, pj, k, 1); // repaint
        }
    }

}

int main(){
    cin >> n;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> mat[i][j];
        }
    }
    dfs(0,0,0);
}