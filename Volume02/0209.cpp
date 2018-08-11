#include<iostream>
#include<cstring>
using namespace std;

int n, m;
int scene[100][100], pict[50][50];
int x, y;

bool check0(int si, int sj){
    bool first = true;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(pict[i][j] == -1)    continue;

            if(pict[i][j] == scene[si+i][sj+j]){
                if(first){
                    first = false;
                    x = sj+j; y = si+i;
                }
            }else{
                return false;
            }
        }
    }
    return true;
}

bool check90(int si, int sj){
    bool first = true;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(pict[m-1-j][i] == -1)    continue;

            if(pict[m-1-j][i] == scene[si+i][sj+j]){
                if(first){
                    first = false;
                    x = sj+j; y = si+i;
                }
            }else{
                return false;
            }
        }
    }
    return true;
}

bool check180(int si, int sj){
    bool first = true;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(pict[m-1-i][m-1-j] == -1)    continue;

            if(pict[m-1-i][m-1-j] == scene[si+i][sj+j]){
                if(first){
                    first = false;
                    x = sj+j; y = si+i;
                }
            }else{
                return false;
            }
        }
    }
    return true;
}

bool check270(int si, int sj){
    bool first = true;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(pict[j][m-1-i] == -1)    continue;

            if(pict[j][m-1-i] == scene[si+i][sj+j]){
                if(first){
                    first = false;
                    x = sj+j; y = si+i;
                }
            }else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    while(1){
        cin >> n >> m;
        if(n+m == 0)    break;

        memset(scene, -1, sizeof(scene));
        memset(pict, -1, sizeof(pict));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> scene[i][j];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                cin >> pict[i][j];
            }
        }

        bool cont = true;
        
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << pict[m-1-i][m-1-j] << " ";
        //     }
        //     cout << endl;
        // }

        for(int i = 0; i <= n-m && cont; i++){
            for(int j = 0; j <= n-m && cont; j++){
                if(check0(i,j)){
                    cout << x+1 << " " << y+1 << endl;
                    cont = false;
                    break;
                }
                if(check90(i,j)){
                    cout << x+1 << " " << y+1 << endl;
                    cont = false;
                    break;
                }
                if(check180(i,j)){
                    cout << x+1 << " " << y+1 << endl;
                    cont = false;
                    break;
                }
                if(check270(i,j)){
                    cout << x+1 << " " << y+1 << endl;
                    cont = false;
                    break;
                }
            }
        }

        if(cont)    cout << "NA" << endl;
    }
    return 0;
}