#include<iostream>
using namespace std;

int main(){
    int k, a, b, c, d, n, m, x;
    scanf("%d", &k);
    int from[k], to[k], tea[k], stu[k];
    for(int i = 0; i < k; i++){
        scanf("%d:%d-%d:%d", &a, &b, &c, &d);
        from[i] = a*60+b;
        to[i] = c*60+d;
        tea[i] = stu[i] = 0;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        while(x-- > 0){
            scanf("%d:%d-%d:%d", &a, &b, &c, &d);
            int f = a*60+b, t = c*60+d;
            for(int j = 0; j < k; j++){
                if(f <= from[j] && to[j] <= t)  tea[j]++;
            }
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &x);
        while(x-- > 0){
            scanf("%d:%d-%d:%d", &a, &b, &c, &d);
            int f = a*60+b, t = c*60+d;
            for(int j = 0; j < k; j++){
                if(f <= from[j] && to[j] <= t)  stu[j]++;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < k; i++)  ans += min(tea[i], stu[i]);
    cout << ans << endl;
    return 0;
}