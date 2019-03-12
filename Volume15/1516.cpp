#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    char mat[3][3];
    for(int i = 0; i < 3; i++)  for(int j = 0; j < 3; j++)  mat[i][j] = (char)('A'+i*3+j);
    string s;
    while(cin >> s){
        int ni, nj;
        for(int i = 0; i < 3; i++)  for(int j = 0; j < 3; j++) if(mat[i][j]==s[0])  ni = i, nj = j;
        bool valid = true;
        for(int i = 1; i < s.length(); i++){
            for(int k = 0; k < 4; k++){
                int nni = ni+di[k], nnj = nj+dj[k];
                if(inRange(nni, 0, 3) && inRange(nnj, 0, 3) && mat[nni][nnj]==s[i]){
                    ni = nni, nj = nnj;
                    break;
                }
                if(k == 3)  valid = false;
            }
        }
        if(valid)   cout << s << endl;
    }
    return 0;
}