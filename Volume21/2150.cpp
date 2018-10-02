#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    bool nonprime[120000] = {};
    vector<int> prime;
    for(int i = 2; i < 120000; i++){
        if(!nonprime[i]){
            prime.push_back(i);
            for(int j = i+i; j < 120000; j += i)    nonprime[j] = true;
        }
    }

    int n, p;

    while(cin >> n >> p, n+p != -2){
        vector<int> use;
        auto it = upper_bound(prime.begin(), prime.end(), n);
        for(int i = 0; i < 100; i++) use.push_back(*it), it++;

        vector<int> sum;
        for(int i = 0; i < 100; i++) for(int j = i; j < 100; j++) sum.push_back(use[i]+use[j]);
        sort(sum.begin(), sum.end());

        cout << sum[p-1] << endl;
    }
    return 0;
}