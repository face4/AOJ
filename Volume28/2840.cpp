#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void no(){
    cout << "no" << endl;
    exit(0);
}

int main(){
    string t, p;
    cin >> t >> p;
    vector<int> v[26];
    for(int i = 0; i < t.length(); i++){
        v[t[i]-'a'].push_back(i);
    }
    int n = p.length();
    vector<int> l(n), r(n);
    int now = 0;
    for(int i = 0; now < n && i < t.length(); i++){
        if(t[i] == p[now]){
            l[now++] = i;
        }
    }
    if(now != n)    no();
    now = n-1;
    for(int i = t.length()-1; now >= 0 && i >= 0; i--){
        if(t[i] == p[now]){
            r[now--] = i;
        }
    }
    if(now != -1)   no();
    if(v[p[0]-'a'][0] != l[0] || v[p.back()-'a'].back() != r[n-1])  no();
    for(int i = 1; i+1 < n; i++){
        int cind = p[i]-'a';
        int j = *upper_bound(v[cind].begin(),v[cind].end(),l[i-1]);
        int k = *(--lower_bound(v[cind].begin(), v[cind].end(),r[i+1]));
        if(j != k)  no();
    }
    cout << "yes" << endl;
    return 0;
}