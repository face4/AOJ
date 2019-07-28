#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int di[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
int dj[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[9][9] = {};
    for(int i = 1; i < s.length(); i++){
        int from = s[i-1]-'1', to = s[i]-'1';
        cnt[from][to]++;
        cnt[to][from]++;
    }
    vector<int> ans(9), arr(9);
    for(int i = 0; i < 9; i++)  arr[i] = i;
    int ma = 1<<30;
    do{
        int rev[9];
        for(int i = 0; i < 9; i++){
            rev[arr[i]] = i;
        }
        int tmp = 0;
        for(int i = 0; i < 9; i++){
            for(int j = i+1; j < 9; j++){
                int dist = abs(di[rev[i]]-di[rev[j]])+abs(dj[rev[i]]-dj[rev[j]]);
                tmp += dist * cnt[i][j];
            }
        }
        if(tmp < ma){
            ma = tmp;
            ans = arr;
        }
    }while(next_permutation(arr.begin(), arr.end()));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << ans[i*3+j]+1;
        }
        cout << endl;
    }
    return 0;
}