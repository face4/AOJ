#include<iostream>
#include<set>
using namespace std;

int dx[12] = {-2, -2, -2,  2, 2, 2, -1, 0, 1, -1,  0,  1};
int dy[12] = {-1,  0,  1, -1, 0, 1,  2, 2, 2, -2, -2, -2};

int main(){
    int px, py, n, x, y;
    while(cin >> px >> py){
        if(px + py == 0)    break;

        set<pair<int,int>> pyon;
        pyon.insert({px,py});
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> x >> y;
            set<pair<int,int>> next;
            for(pair<int,int> p : pyon){
                for(int j = 0; j < 12; j++){
                    int newx = p.first + dx[j];
                    int newy = p.second + dy[j];
                    if(0 <= newx && newx <= 9 && 0 <= newy && newy <= 9 && max(abs(newx-x), abs(newy-y)) <= 1){
                        next.insert({newx, newy});
                    }
                }
            }
            pyon = next;
        }

        if(pyon.size() > 0){
            cout << "OK" << endl;
        }else{
            cout << "NA" << endl;
        }

    }

    return 0;
}