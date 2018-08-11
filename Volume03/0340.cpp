#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;

    int p[n];
    for(int i = 0; i < n; i++)  cin >> p[i];

    int ans = INT_MAX;
    for(int i = 0; i <= p[0]; i++){
        int tmp = i, before = i;
        for(int j = 0; j < n-1; j++){
            tmp += 2 * max(0, p[j]-before);
            before = max(0, p[j] - before);
        }
        tmp += max(0, p[n-1]-before);
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}