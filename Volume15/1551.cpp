#include<iostream>
#include<list>
#include<map>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    bool b[100] = {};
    for(int i = 0; i < m; i++){
        int a, l;
        cin >> a >> l;
        for(int i = 1; i <= l; i++) b[(a+i)%n] = true;
    }
    list<int> l;
    int cur = 0;
    while(cur < n){
        if(b[cur]){
            int next = cur;
            while(b[next] && next < n)  next++;
            l.push_back(next-cur);
            cur = next;
        }else{
            cur++;
        }
    }

    if(l.size() == 1){
        cout << l.front() << " " << 1 << endl;
        return 0;
    }

    if(b[0] && b[n-1]){
        int x = l.front() + l.back();
        l.pop_front();  l.pop_back();
        l.push_back(x);
    }

    map<int,int> ans;
    for(auto it = l.begin(); it != l.end(); it++)   ans[*it]++;
    for(auto it = ans.rbegin(); it != ans.rend(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }

    return 0;
}