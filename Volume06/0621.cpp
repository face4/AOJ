#include<iostream>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    int a[h][3];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < 3; j++){
            a[i][j] = w;
        }
    }

    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == 'W') a[i][0]--;
            if(s[j] == 'B') a[i][1]--;
            if(s[j] == 'R') a[i][2]--;
        }
    }

    int ans = 3000;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= h; j++){
            if(i + j >= h)  continue;
            int k = h-i-j;
            int tmp = 0;
            for(int x = 0; x < i; x++)      tmp += a[x][0];
            for(int x = i; x < i+j; x++)    tmp += a[x][1];
            for(int x = i+j; x < h; x++)    tmp += a[x][2];
            ans = min(ans, tmp);
        }
    }

    cout << ans << endl;

    return 0;
}