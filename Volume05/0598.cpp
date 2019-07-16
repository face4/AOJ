#include<iostream>
#include<vector>
using namespace std;

int di[4] = {-1,-1, 0, 0};
int dj[4] = {-1, 0,-1, 0};

int main(){
    string joi = "JOI";
    int m, n;
    cin >> m >> n;
    vector<vector<char>> mat(m+2, vector<char>(n+2, '.')), flag(2, vector<char>(2));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < 2; i++)  for(int j = 0; j < 2; j++)  cin >> flag[i][j];
    auto f = [&](int i, int j)->bool{
        for(int k = 0; k < 2; k++){
            for(int l = 0; l < 2; l++){
                if(mat[i+k][j+l] != flag[k][l]) return false;
            }
        }
        return true;
    };
    int base = 0;
    for(int i = 1; i <= m-1; i++){
        for(int j = 1; j <= n-1; j++){
            if(f(i,j))  base++;
        }
    }
    int add = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            char c = mat[i][j];
            int def = 0;
            for(int k = 0; k < 4; k++)  if(f(i+di[k],j+dj[k]))  def++;
            for(int k = 0; k < 3; k++){
                mat[i][j] = joi[k];
                int tmp = 0;
                for(int l = 0; l < 4; l++)  if(f(i+di[l],j+dj[l]))  tmp++;
                add = max(add, tmp-def);
            }
            mat[i][j] = c;
        }
    }
    cout << base+add << endl;
    return 0;
}