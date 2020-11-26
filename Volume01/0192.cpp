#include<iostream>
#include<vector>
#include<queue>
#include<stack> 
using namespace std;
typedef pair<int,int> pii;

int getEmpty(int n, stack<pii> *s){
    for(int i = 0; i < n; i++){
        if(s[i].empty())    return i;
    }
    return -1;
}

int getG(int n, stack<pii> *s, int now, int cnow){
    int ret = -1, diff = 1<<30;
    for(int i = 0; i < n; i++){
        if(s[i].size() == 2)    continue;
        int residual = s[i].top().first-now;
        if(residual >= cnow && residual-cnow < diff){
            ret = i;
            diff = residual-cnow;
        }
    }
    return ret;
}

int getS(int n, stack<pii> *s, int now, int cnow){
    int ret = -1, diff = 1<<30;
    for(int i = 0; i < n; i++){
        if(s[i].size() == 2)    continue;
        int residual = s[i].top().first-now;
        if(cnow-residual < diff){
            ret = i;
            diff = cnow-residual;
        }
    }
    return ret;
}

int main(){
    int m, n;
    while(cin >> m >> n, m+n){
        queue<pair<int,pii>> wait;
        stack<pii> park[m];
        vector<int> ans;
        priority_queue<int> t;
        for(int i = 0; i < n; i++){
            int x;  cin >> x;
            wait.push({i*10, {x, i+1}});
            t.push(-i*10);
        }
        while(!t.empty()){
            int now = -t.top();    t.pop();

            // leave
            for(int i = 0; i < m; i++){
                while(!park[i].empty() && park[i].top().first <= now){
                    ans.push_back(park[i].top().second);
                    park[i].pop();
                }
            }

            // park
            while(!wait.empty() && wait.front().first <= now){
                int tmp = getEmpty(m, park);    
                if(tmp != -1)   goto PARK;
                tmp = getG(m, park, now, wait.front().second.first);
                if(tmp != -1)   goto PARK;
                tmp = getS(m, park, now, wait.front().second.first);
                if(tmp != -1)   goto PARK;
                if(tmp == -1)   break;
                PARK:
                wait.front().second.first += now;
                park[tmp].push(wait.front().second);
                t.push(-wait.front().second.first);
                wait.pop();
            }
        }
        for(int i = 0; i < n; i++)  cout << ans[i] << " \n"[i==ans.size()-1];
    }
    return 0;
}