#include<iostream>
#include<set>
using namespace std;

int main(){
    int n, a;
    while(cin >> n, n){
        int sum = 0;
        set<int> s;
        s.insert(0);

        for(int i = 0; i < n; i++){
            cin >> a;
            sum += a;
            set<int> next;
            for(int x : s){
                next.insert(x+a);
                next.insert(x);
            }
            s = next;
        }

        int ans = sum;
        for(int x : s)  ans = min(ans, abs(2*x-sum));
        cout << ans << endl;
    }
    return 0;
}