#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k, b;
    cin >> n >> k;

    vector<int> t(k);
    for(int i = 0; i < k; i++)  cin >> t[i];
    sort(t.begin(), t.end());

    for(int i = 0; i < 1<<k; i++){
        int d = 0;
        vector<int> res;
        for(int j = 0; j < k; j++){
            if(i & 1<<j){
                d |= 1<<t[j];
                res.push_back(t[j]);
            }
        }
        cout << d << ":";
        for(int j : res)    cout << " " << j;
        cout << endl;
    }

    return 0;
}