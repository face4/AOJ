#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == -1) break;
        
        if(n == 0){
            cout << 0 << endl;
            continue;
        }

        vector<int> res;
        while(n != 0){
            res.push_back(n%4);
            n /= 4;
        }

        reverse(res.begin(), res.end());
        for(int i : res)    cout << i;
        cout << endl;
    }
    return 0;
}