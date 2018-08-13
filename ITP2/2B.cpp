#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, q, a, b, c;
    cin >> n >> q;

    vector<queue<int>> v(n);

    for(int i = 0; i < q; i++){
        cin >> a;

        if(a == 0){
            cin >> b >> c;
            v[b].push(c);
        }else if(a == 1){
            cin >> b;
            if(!v[b].empty())   cout << v[b].front() << endl;
        }else if(a == 2){
            cin >> b;
            if(!v[b].empty())   v[b].pop();
        }
    }

    return 0;
}