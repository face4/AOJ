#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ng[26];
int ten[8];
int kiyo[26];
vector<char> vc;

int dfs(int i, int used, int sum){
    if(i == vc.size())  return sum==0;
    int ret = 0;
    for(int j = 0; j < 10; j++){
        if((used>>j)&1) continue;
        if(j == 0 && ng[vc[i]-'A']) continue;
        ret += dfs(i+1, used|(1<<j), sum+j*kiyo[vc[i]-'A']);
    }
    return ret;
}

int main(){
    ten[0] = 1;
    for(int i = 1; i < 8; i++){
        ten[i] = ten[i-1]*10;
    }

    int n;
    while(cin >> n, n){
        // init
        for(int i = 0; i < 26; i++) ng[i] = kiyo[i] = 0;
        vc.clear();

        string s[n];
        for(int i = 0; i < n; i++)  cin >> s[i];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < s[i].length(); j++){
                vc.push_back(s[i][j]);
                kiyo[s[i][j]-'A'] += (i==n-1 ? -1 : 1) * ten[s[i].length()-1-j];
            }
            if(s[i].length() > 1)   ng[s[i][0]-'A'] = true;
        }
        sort(vc.begin(), vc.end());
        vc.erase(unique(vc.begin(),vc.end()), vc.end());
        cout << dfs(0, 0, 0) << endl;
    }

    return 0;
}