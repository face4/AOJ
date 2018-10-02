#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    bool nonp[1500000] = {};
    vector<int> p;
    for(int i = 2; i < 1500000; i++){
        if(!nonp[i]){
            p.push_back(i);
            for(int j = i+i; j < 1500000; j += i)   nonp[j] = true;
        }
    }

    int n;
    while(cin >> n, n){
        if(!nonp[n]){
            cout << 0 << endl;
        }else{
            auto it = upper_bound(p.begin(), p.end(), n);
            cout << *it - *(it-1) << endl;
        }
    }

    return 0;
}