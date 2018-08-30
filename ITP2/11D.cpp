#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < 1<<n; i++){
        vector<int> bit;
        for(int j = 0; j < n; j++)  if(i & 1<<j)    bit.push_back(j);
        if(bit.size() != k) continue;
        cout << i << ":";
        for(int j : bit)    cout << " " << j;
        cout << endl;
    }
    
    return 0;
}