#include<iostream>
using namespace std;

int enc(int i){
    if(i < 15)  return 0;
    if(i < 21)  return 1;
    return 2;
}

string s[3] = {"lunch", "dinner", "midnight"};

int main(){
    int n;
    while(scanf("%d\n", &n), n){
        int h, m, mm, ans[3][2] = {};
        while(n-- > 0){
            scanf("%d:%d %d\n", &h, &m, &mm);
            if(h < 2)   h += 24;
            if(15 <= h && h < 18)   continue;
            if(m > mm)  mm += 60;
            int ok = (mm-m <= 8);
            ans[enc(h)][ok]++;
        }
        for(int i = 0; i < 3; i++){
            cout << s[i] << " ";
            if(ans[i][0]+ans[i][1] == 0){
                cout << "no guest" << endl;
            }else{
                cout << 100*ans[i][1]/(ans[i][0]+ans[i][1]) << endl;
            }
        }
    }
    return 0;
}