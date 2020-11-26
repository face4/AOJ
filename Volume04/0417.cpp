#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    queue<int> q[n];
    while(m--){
        int a, b;
        cin >> a >> b;
        if(a == 0){
            cout << q[--b].front() << endl;
            q[b].pop();
        }else{
            int ind = 0;
            for(int i = 1; i < n; i++){
                if(q[ind].size() > q[i].size()) ind = i;
            }
            q[ind].push(b);
        }
    }
    return 0;
}