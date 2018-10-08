#include<iostream>
using namespace std;

int go[100005] = {};

int main(){
    int n, a, b;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        go[a]++;
        go[b+1]--;
    }

    int ans = 0, sum = 1;
    for(int i = 2; i < 100005; i++){
        sum += go[i];
        if(sum >= i)    ans = i;
    }

    cout << max(0, ans-1) << endl;

    return 0;
}