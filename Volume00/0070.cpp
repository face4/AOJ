#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n, s;
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int mat[10][10001] = {};
    
    do{
        int tmp = 0;
        for(int i = 0; i < 10; i++){
            tmp += (i+1) * a[i];
            mat[i][tmp]++;
        }
    }while(next_permutation(a, a+10));

    while(cin >> n >> s){
        int ans = mat[n-1][s];
        for(int i = 1; i <= 10-n; i++)  ans /= i;
        cout << ans << endl;
    }

    return 0;
}