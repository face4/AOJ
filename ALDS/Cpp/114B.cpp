#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ull;

const ull B = 100000007;

vector<int> contain(string a, string b){
    vector<int> v;
    int al = a.length(), bl = b.length();
    if(al > bl) return v;

    ull t = 1;
    for(int i = 0; i < al; i++) t *= B;

    ull ah = 0, bh = 0;
    for(int i = 0; i < al; i++) ah = ah*B + a[i];
    for(int i = 0; i < al; i++) bh = bh*B + b[i];

    for(int i = 0; i + al <= bl; i++){
        if(ah == bh)    v.push_back(i);
        if(i+al < bl)   bh = bh*B - b[i]*t + b[i+al];
    }

    return v;
}

int main(){
    string t, p;
    cin >> t >> p;
    vector<int> v = contain(p, t);
    for(int x : v)  cout << x << endl;
    return 0;
}
