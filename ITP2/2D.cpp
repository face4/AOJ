#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main(){
    int n, q, a, b, c;
    cin >> n >> q;

    vector<list<int>> v(n);

    for(int i = 0; i < q; i++){
        cin >> a;
        if(a == 0){
            cin >> b >> c;
            v[b].push_back(c);
        }else if(a == 1){
            cin >> b;
            list<int>::iterator it = v[b].begin();
            if(it != v[b].end())    cout << *it;

            while(++it != v[b].end()){
                cout << " " << *it;
            }
            cout << endl;
        }else if(a == 2){
            cin >> b >> c;
            v[c].splice(v[c].end(), v[b]);
        }
    }
    return 0;
}