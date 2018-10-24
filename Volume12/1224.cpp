#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> tanka, tankb;
    for(int i = 1; i*i*i <= 151200; i++)    tanka.push_back(i*i*i);
    for(int j = 1; j*(j+1)*(j+2)/6 <= 151200; j++)  tankb.push_back(j*(j+1)*(j+2)/6);

    int n;
    while(cin >> n, n){
        int ans = 0;
        for(int i = 0; i < tanka.size(); i++){
            if(tanka[i] > n)    break;
            int add = 0;
            auto it = upper_bound(tankb.begin(), tankb.end(), n-tanka[i]);
            if(it != tankb.begin()){
                it--;
                add = *it;
            }
            ans = max(ans, add+tanka[i]);
        }
        for(int i = 0; i < tankb.size(); i++){
            if(tankb[i] > n)    break;
            int add = 0;
            auto it = upper_bound(tanka.begin(), tanka.end(), n-tankb[i]);
            if(it != tanka.begin()){
                it--;
                add = *it;
            }
            ans = max(ans, add+tankb[i]);
        }
        cout << ans << endl;
    }
    
    return 0;
}