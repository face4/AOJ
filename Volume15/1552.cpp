#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n), x(n-1);
    for(int i = 0; i < n; i++)  cin >> v[i];
    for(int i = 0; i < n-1; i++)    x[i] = v[i+1]-v[i];
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for(int i = 1; i < n-1; i++){
        if(x[i-1] < 0 && x[i] > 0)  e++;
        if(x[i-1] > 0 && x[i] < 0)  d++;
    }
    int cur = 0;
    while(cur < n-1 && x[cur] == 0)  cur++;

    while(cur < n-1){
        if(x[cur] != 0){
            cur++;
            continue;
        }
        int next = cur;
        while(next < n-1 && x[next] == 0)  next++;
        if(next == n-1) break;
        if(x[cur-1] < 0 && x[next] > 0)         b++;
        else if(x[cur-1] > 0 && x[next] < 0)    a++;
        else                                    c++;
        cur = next;
    }
    printf("%d %d %d %d %d\n", a, b, c, d, e);
    return 0;
}