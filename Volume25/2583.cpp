#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<int> depth[1002];
        string s[n];
        for(int i = 0; i < n; i++){
            cin >> s[i];
            int j;
            for(j = s[i].length()-1; j >= 0; j--){
                if(s[i][j] == '.'){
                    s[i][j] = '+';
                    break;
                }
            }
            depth[j+1].push_back(i);
        }
        for(int i = 1; i < 1002; i++){
            for(int j = 1; j < depth[i].size(); j++){
                bool check = true;
                for(int k = depth[i][j-1]+1; k < depth[i][j]; k++){
                    check &= (s[k][i-1] == '.');
                }
                if(!check)  continue;
                for(int k = depth[i][j-1]+1; k < depth[i][j]; k++){
                    s[k][i-1] = '|';
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(char x : s[i]){
                cout << (x == '.' ? ' ' : x);
            }
            cout << endl;
        }
    }
    return 0;
}