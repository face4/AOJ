#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool judge(vector<int> v){
    for(int i = 0; i < 8; i++)  if(v[i] != v[i+1])  return false;
    for(int i = 9; i < 11; i++) if(v[i] != v[i+1])  return false;
    for(int i = 12; i < 14; i++) if(v[i] != v[i+1])  return false;
    for(int i = 15; i < 17; i++) if(v[i] != v[i+1])  return false;
    for(int i = 18; i < 20; i++) if(v[i] != v[i+1])  return false;
    for(int i = 21; i < 29; i++) if(v[i] != v[i+1])  return false;
    return true;
}

pair<int,int> rot[4][5] = {
    {{23,0}, {26,3}, {29,6}, {9,20}, {15,17}},
    {{21,6}, {22,7}, {23,8}, {12,17}, {9,11}},
    {{21,2}, {24,5}, {27,8}, {11,18}, {12,14}},
    {{27,0}, {28,1}, {29,2}, {14,15}, {18,20}},
};

int main(){
    int n;
    cin >> n;

    while(n-- > 0){
        vector<int> v(30);
        for(int i = 0; i < 30; i++) cin >> v[i];
        
        queue<pair<int,vector<int>>> q;
        q.push({0, v});

        while(!q.empty()){
            auto p = q.front(); q.pop();

            if(judge(p.second)){
                cout << p.first << endl;
                break;
            }
            
            v = p.second;

            for(int i = 0; i < 4; i++){
                vector<int> n = v;
                for(int j = 0; j < 5; j++){
                    swap(n[rot[i][j].first], n[rot[i][j].second]);
                }
                
                q.push({p.first+1, n});
            }
        }

    }

    return 0;
}