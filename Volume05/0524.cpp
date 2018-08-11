#include<iostream>
#include<set>
using namespace std;

int m, n;

int main(){
    while(cin >> m, m){
        set<pair<int,int>> cons, sky;
        int x, y;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            cons.insert({x,y});
        }
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            sky.insert({x,y});
        }

        pair<int,int> s = *(cons.begin());

        for(pair<int,int> target : sky){
            int diffx = target.first - s.first;
            int diffy = target.second - s.second;

            bool judge = true;
            for(pair<int,int> c : cons){
                pair<int,int> p(diffx + c.first, diffy + c.second);
                if(sky.find(p) == sky.end()){
                    judge = false;
                    break;
                }
            }

            if(judge){
                cout << diffx << " " << diffy << endl;
                break;
            }
        }
    }
    return 0;
}