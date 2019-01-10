#include<iostream>
#include<set>
#include<tuple>
using namespace std;

int main(){
    int n, h;
    while(cin >> n >> h, n+h){
        set<tuple<int,int,int>> s;
        string axis;
        int a, b;
        while(h-- > 0){
            cin >> axis >> a >> b;
            for(int i = 1; i <= n; i++){
                if(axis == "xy"){
                    s.insert(make_tuple(a,b,i));
                }else if(axis == "xz"){
                    s.insert(make_tuple(a,i,b));
                }else if(axis == "yz"){
                    s.insert(make_tuple(i,a,b));
                }
            }
        }
        cout << n*n*n - s.size() << endl;
    }
    return 0;
}