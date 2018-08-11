#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    // 要素
    int a[100][100] = {};
    // 要素の横方向の累積和を取る
    int sum[101][101] = {};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum[i][j+1] += sum[i][j] + a[i][j];
        }
    }
    
    // 横方向の区間[i,j]を固定し、縦方向に動かして部分行列の和の最大値を取る
    int ans = INT_MIN;
    for(int i = 0; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int tmp = 0;
            // 行kを0~nまで動かして最大値を探す
            // tmpが負になった時点でtmpをリセットしてしまって良い
            // (１つ前のループでtmpをmax関数に通しているので問題ない)
            for(int k = 0; k < n; k++){
                if(tmp < 0){
                    tmp = sum[k][j] - sum[k][i];
                }else{
                    tmp += sum[k][j] - sum[k][i];
                }
                ans = max(ans, tmp);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
