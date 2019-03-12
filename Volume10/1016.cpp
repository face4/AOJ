#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> fib(1002);
    fib[0] = 1; fib[1] = 2;
    for(int i = 2; i <= 1001; i++)  fib[i] = (fib[i-1]+fib[i-2])%1001;
    int v, d;
    while(cin >> v >> d){
        vector<int> x;
        for(int i = 1; i <= v; i++) x.push_back(fib[i]);
        sort(x.begin(), x.end());
        int now = x[0], cnt = 1;
        for(int i = 1; i < v; i++){
            if(x[i]-x[i-1] >= d)    cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}