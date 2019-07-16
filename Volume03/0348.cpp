#include<iostream>
#include<vector>
#include<set>
using namespace std;

// シミュレート解
int main(){
    set<int> hand[2];
    int n;  cin >> n;
    while(n-- > 0){
        hand[0].clear(), hand[1].clear();
        int vergea = 0, vergeb = 0, one = 0, thirteen = 0;
        for(int i = 0; i < 6; i++){
            int x;  cin >> x;
            hand[0].insert(x);
            if(x == 1)  one = -1;
            if(x == 13) thirteen = -1;
        }
        for(int i = 1; i <= 13; i++){
            if(i == 7 || hand[0].count(i))  continue;
            hand[1].insert(i);
            if(i == 1)  one = 1;
            if(i == 13) thirteen = 1;
        }
        if(one*thirteen == 0){
            cout << (one+thirteen==2 ? "no" : "yes") << endl;
            continue;
        }
        int l = 6, r = 8, turn = 0;
        while(hand[0].size() && hand[1].size()){
            if(2*turn-1 == one){
                // prior on lower 
                if(hand[turn].count(l)){
                    hand[turn].erase(l);
                    l--;
                    turn = 1-turn;
                    continue;
                }else if(hand[turn].count(r)){
                    hand[turn].erase(r);
                    r++;
                    turn = 1-turn;
                    continue;
                }
            }else{
                // prior on higher
                if(hand[turn].count(r)){
                    hand[turn].erase(r);
                    r++;
                    turn = 1-turn;
                    continue;
                }else if(hand[turn].count(l)){
                    hand[turn].erase(l);
                    l--;
                    turn = 1-turn;
                    continue;
                }
            }
            turn = 1-turn;
        }
        cout << (hand[0].size()==0 ? "yes" : "no") << endl;
    }
    return 0;
}

// 再帰解
// set<int> hand[2];

// bool dfs(int low, int high, int turn){
//     if(turn == 1){
//         if(hand[0].size() == 0) return true; // 後手にターンが回った時点で先手のカードが0枚
//     }else if(turn == 0){
//         if(hand[1].size() == 0) return false;// 先手にターンが回った時点で後手のカードが0枚
//     }
//     int cnt = 0;
//     if(turn == 0){
//         if(hand[turn].count(low)){
//             cnt++;
//             hand[turn].erase(low);
//             bool ret = dfs(low-1, high, 1-turn);
//             hand[turn].insert(low);
//             if(ret) return true;
//         }
//         if(hand[turn].count(high)){
//             cnt++;
//             hand[turn].erase(high);
//             bool ret = dfs(low, high+1, 1-turn);
//             hand[turn].insert(high);
//             if(ret) return true;
//         }
//         if(cnt == 0){
//             if(dfs(low, high, 1-turn))  return true;
//         }
//         return false;
//     }else if(turn == 1){
//         if(hand[turn].count(low)){
//             cnt++;
//             hand[turn].erase(low);
//             bool ret = dfs(low-1, high, 1-turn);
//             hand[turn].insert(low);
//             if(!ret) return false;
//         }
//         if(hand[turn].count(high)){
//             cnt++;
//             hand[turn].erase(high);
//             bool ret = dfs(low, high+1, 1-turn);
//             hand[turn].insert(high);
//             if(!ret) return false;
//         }
//         if(cnt == 0){
//             if(!dfs(low, high, 1-turn))  return false;
//         }
//         return true;
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//     while(n-- > 0){
//         hand[0].clear(); hand[1].clear();
//         for(int i = 0; i < 6; i++){
//             int x;  cin >> x;
//             hand[0].insert(x);
//         }
//         for(int i = 1; i <= 13; i++){
//             if(i == 7 || hand[0].count(i))  continue;
//             hand[1].insert(i);
//         }
//         cout << (dfs(6, 8, 0) ? "yes" : "no") << endl;
//     }
//     return 0;
// }