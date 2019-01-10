#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    list<int> l;
    
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++)  l.push_back(i);

    auto it = l.begin();

    int a;
    for(int i = 0; i < m; i++){
        cin >> a;
        if(a%2 == 0){
            while(a-- > 0){
                it++;
                if(it == l.end())   it = l.begin();
            }
            it = l.erase(it);
            if(it == l.end())   it = l.begin();
        }else{
            while(a-- > 0){
                if(it == l.begin()) it = l.end();
                it--;
            }
            it = l.erase(it);
            if(it == l.end())   it = l.begin();
        }
    }

    for(int i = 0; i < q; i++){
        cin >> a;
        auto x = lower_bound(l.begin(), l.end(), a);
        cout << (x != l.end() && *x == a) << endl;
    }

    return 0;
}