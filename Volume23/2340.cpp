#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll sum = 0;
    while(n-- > 0){
        int x; char c;
        cin >> x >> c >> x;
        if(c == '(')    sum += x;
        else            sum -= x;
        cout << (sum==0 ? "Yes" : "No") << endl;
    }
    return 0;
}
