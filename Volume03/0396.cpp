#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int w, h;
    cin >> w >> h;
    vector<int> a(w);
    for(int i = 0; i < w; i++)  cin >> a[i];
    sort(a.rbegin(), a.rend());
    priority_queue<int> q;
    for(int i = 0; i < h; i++){
        int x;  cin >> x;
        if(x)   q.push(x);
    }
    bool valid = true;
    for(int i = 0; i < w; i++){
        if(a[i] > q.size()){
            valid = false;
        }else{
            vector<int> v;
            while(a[i]-- > 0){
                int t = q.top();    q.pop();
                if(t-1 > 0) v.push_back(t-1);
            }
            for(int t : v)  q.push(t);
        }
    }
    valid &= (q.size() == 0);
    cout << valid << endl;
    return 0;
}