#include<iostream>
#include<vector>
#include<cctype>
#include<numeric>
using namespace std;

int n, pos;
vector<string> v;

int f(int d){
    if(isdigit(v[pos].back())){
        int ret =  v[pos].back()-'0';
        pos++;
        return ret;
    }else{
        char op = v[pos].back();
        pos++;
        vector<int> child;
        while(pos < n && v[pos].length() == d+1){
            child.push_back(f(d+1));
        }
        if(op == '+'){
            return accumulate(child.begin(), child.end(), 0);
        }else{
            int ret = 1;
            for(int x : child)  ret *= x;
            return ret;
        }
    }
}

int main(){
    while(cin >> n, n){
        v.clear();
        v.resize(n);
        for(int i = 0; i < n; i++)  cin >> v[i];
        pos = 0;
        cout << f(1) << endl;
    }
    return 0;
}