// 解説AC
#include<iostream>
#include<vector>
using namespace std;

int f(int n, int k){
    if(n == 1)  return 0;
    return (f(n-1, k)+k)%n;
}

int main(){
    int n, k, m;
    while(cin >> n >> k >> m, n+k+m){
        //cout << (f(n-1,k)+m)%n+1 << endl;
        vector<int> v;
        for(int i = 1; i <= n; i++) v.push_back(i);
        v.erase(v.begin()+m-1);
        int pos = (m-2+k)%((int)v.size());
        while(v.size() > 1){
            v.erase(v.begin()+pos);
            pos = (pos-1+k)%((int)(v.size()));
        }
        cout << v[0] << endl;
    }
    return 0;
}
