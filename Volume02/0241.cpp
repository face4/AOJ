#include<iostream>
#include<cmath>
using namespace std;

int first[4], second[4], ans[4];

int table[4][4] = {
    {1, 2, 3, 4},
    {2, -1, 4, -3},
    {3, -4, -1, 2},
    {4, 3, -2, -1}
};

void calc(){
    for(int i = 0; i < 4; i++)  ans[i] = 0;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int judge = table[i][j];
            if(judge < 0)   ans[abs(judge)-1] -= first[i]*second[j];
            else            ans[abs(judge)-1] += first[i]*second[j];
        }
    }
}
int main(){
    while(1){
        int n;
        cin >> n;
        
        if(n == 0)  break;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 4; j++)  cin >> first[j];
            for(int j = 0; j < 4; j++)  cin >> second[j];
            calc();
            for(int j = 0; j < 4; j++){
                if(j)   cout << " ";
                cout << ans[j];
            }
            cout << endl;
        }
        
    }
    return 0;
}
