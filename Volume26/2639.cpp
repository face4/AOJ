#include<iostream>
#include<set>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int ans = c;
    set<int> s;
    while(ans % (a+b) > a){
        if(s.count(ans%(a+b))){
            ans = -1;
            break;
        }
        s.insert(ans%(a+b));
        ans += 60;
    }

    cout << ans << endl;
    
    return 0;
}