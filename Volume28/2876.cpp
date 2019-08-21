#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    /*
    vector<int> ans;
    map<int,int> x, y;
    int ng = 0;
    for(int i = 0; i < n; i++){
        int j = n-1-i;
        if(x[a[i]]==y[a[i]])  ng++;
        x[a[i]]++;
        if(x[a[i]] == y[a[i]])  ng--;
        if(x[a[j]]==y[a[j]])  ng++;
        y[a[j]]++;
        if(x[a[j]] == y[a[j]])  ng--;
        if(ng == 0) ans.push_back(i+1);
    }
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i+1==ans.size()];
    */

    // editorial
    vector<int> ans;
    priority_queue<int> x, y;
    for(int i = 0; i < n; i++){
        int j = n-1-i;
        x.push(a[i]);
        y.push(a[j]);
        while(x.size() && x.top()==y.top())   x.pop(), y.pop();
        if(x.size() == 0)   ans.push_back(i+1);
    }
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i+1==ans.size()];
    return 0;
}