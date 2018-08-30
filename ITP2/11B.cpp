#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k, b;
    cin >> n >> k;
    vector<int> subset(k);
    for(int i = 0; i < k; i++)  cin >> subset[i];

    for(int i = 0; i < 1<<n; i++){
        bool includes = true;
        for(int j : subset) if(~i & 1<<j)   includes = false;
        if(!includes)   continue;
        
        vector<int> res;
        for(int j = 0; j < n; j++)  if(i & 1<<j)    res.push_back(j);
        
        cout << i << ":";
        for(int j : res)    cout << " " << j;
        cout << endl;
    }

    return 0;
}