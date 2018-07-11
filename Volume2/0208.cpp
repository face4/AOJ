// 0, 1, 2, 3, 5, 7, 8, 9を用いた8進表現に変換するだけ
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ref[8] = {0, 1, 2, 3, 5, 7, 8, 9};
int n;

int main(){
    while(cin >> n, n){
        vector<int> decode;
        while(n != 0){
            decode.push_back(ref[n%8]);
            n /= 8;
        }

        reverse(decode.begin(), decode.end());
        for(int x : decode)     cout << x;
        cout << endl;
    }
    return 0;
}