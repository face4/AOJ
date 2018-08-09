#include<iostream>
#include<map>
#include<queue>
using namespace std;
#define inRange(x, a, b) a <= x && x < b

int main(){
    int dx[4] = {-4, -1, 1, 4};
    map<string, int> m;
    queue<pair<string,int>> q;
    q.push({"01234567", 0});

    while(!q.empty()){
        pair<string,int> p = q.front(); q.pop();
        int times = p.second;

        if(m.count(p.first))    continue;

        m[p.first] = times;
        int zpos;
        for(zpos = 0;;zpos++) if(p.first[zpos] == '0')  break;

        for(int i = 0; i < 4; i++){
            int next = zpos + dx[i];
            if(min(next,zpos) == 3 && max(next,zpos) == 4)  continue;

            if(inRange(next, 0, 8)){
                swap(p.first[zpos], p.first[next]);
                if(m.count(p.first) == 0)   q.push({p.first, times+1});
                swap(p.first[zpos], p.first[next]);
            }
        }
    }

    string s;
    while(cin >> s){
        string t;
        for(int i = 0; i < 7; i++){
            cin >> t;
            s += t;
        }
        cout << m[s] << endl;
    }
    return 0;
}