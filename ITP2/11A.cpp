#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < 1<<n; i++){
        vector<int> res;
        for(int j = 0; j < n; j++){
            if(i & 1<<j)    res.push_back(j);
        }
        cout << i << ":";
        for(int j : res)    cout << " " << j;
        cout << endl;
    }

    return 0;
}