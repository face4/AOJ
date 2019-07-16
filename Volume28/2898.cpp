#include<iostream>
#include<vector>
using namespace std;

// O(NloglogN)
int main(){
    int n;
    cin >> n;
    vector<int> p;
    vector<bool> np(n+5, 0);
    for(int i = 2; i < n+1; i++){
        if(np[i])   continue;
        p.push_back(i);
        for(int j = i+i; j < n+5; j += i)   np[j] = true;
    }
    int ans = 0;
    for(int x : p){
        ans += !np[2+x];
    }
    cout << 2*ans << endl;
    return 0;
}