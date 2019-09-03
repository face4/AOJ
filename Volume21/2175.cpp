#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int enc(char c){
    if('2' <= c && c <= '9')    return c-'0';
    if(c == 'T')    return 10;
    if(c == 'J')    return 11;
    if(c == 'Q')    return 12;
    if(c == 'K')    return 13;
    if(c == 'A')    return 14;
    return 0;   // unreachable
}

int main(){
    char c;
    while(cin >> c, c != '#'){
        int trick[2] = {};
        vector<vector<string>> v(4, vector<string>(13));
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 13; j++){
                cin >> v[i][j];
            }
        }
        int lead = 1;
        for(int j = 0; j < 13; j++){
            vector<pair<int,int>> game;
            for(int i = 0; i < 4; i++){
                int score = enc(v[i][j][0]);
                if(v[i][j][1] == v[lead][j][1]) score += 50;
                if(v[i][j][1] == c) score += 100;
                game.push_back({-score, i});
            }
            sort(game.begin(), game.end());
            trick[game[0].second%2]++;
            lead = game[0].second;
        }
        if(trick[0] > trick[1]){
            cout << "NS " << trick[0]-6 << endl;
        }else{
            cout << "EW " << trick[1]-6 << endl;
        }
    }
    return 0;
}
