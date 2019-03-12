#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define inRange(x,a,b) ((a <= x && x <= b) || (a <= x+360 && x+360 <= b))

struct holiday{
    int from, to, s;
};

int diff(int from, int to){
    if(from > to)   to += 360;
    return to-from;
}

int main(){
    int n;
    cin >> n;
    vector<holiday> v;
    int m, d, V, s;
    for(int i = 0; i < n; i++){
        cin >> m >> d >> V >> s;
        v.push_back(holiday({30*(m-1)+d, 30*(m-1)+d+V-1, s}));
    }
    int ans = 1<<30;
    for(int i = 1; i <= 360; i++){
        int tmp = 0;
        for(int j = 0; j < n; j++){
            if(inRange(i,v[j].from,v[j].to)){
                tmp = max(tmp, v[j].s);
            }else{
                tmp = max(tmp, max(0, v[j].s-min(diff(v[j].to, i), diff(i, v[j].from))));
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}