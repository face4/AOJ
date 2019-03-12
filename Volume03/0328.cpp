#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, a, b;
    cin >> n;
    vector<int> cnt(200030, 0);
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cnt[a+b]++;
    }
    for(int i = 0; i < 200020; i++){
        cnt[i+1] += cnt[i]/2;
        if(cnt[i]%2)    cout << i << " " << 0 << endl;
    }
    return 0;
}