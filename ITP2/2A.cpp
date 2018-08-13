#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int n, q, a, b, c;
    cin >> n >> q;

    vector<stack<int>> s(n);
    for(int i = 0; i < q; i++){
        cin >> a;
        if(a == 0){
            cin >> b >> c;
            s[b].push(c);
        }else if(a == 1){
            cin >> b;
            if(!s[b].empty()){
                cout << s[b].top() << endl;
            }
        }else if(a == 2){
            cin >> b;
            if(!s[b].empty())   s[b].pop();
        }
    }
    
    return 0;
}