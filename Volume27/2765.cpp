#include<iostream>
#include<vector>
using namespace std;

int main(){
    int l, n;
    cin >> l >> n;
    int sum = 0, x, w;
    while(n-- > 0){
        cin >> x >> w;
        sum += x*w;
    }
    sum *= -1;
    vector<pair<int,int>> v;
    for(int i = l; i > 0; i--){
        if(sum%i == 0 && sum/i > 0){
            v.push_back({i, abs(sum/i)});
            sum -= abs(sum/i)*i;
        }
        i *= -1;
        if(sum%i == 0 && sum/i > 0){
            v.push_back({i, abs(sum/i)});
            sum -= abs(sum/i)*i;
        }
        i *= -1;
    }
    cout << v.size() << endl;
    for(pair<int,int> p : v)    cout << p.first << " " << p.second << endl;
    return 0;
}