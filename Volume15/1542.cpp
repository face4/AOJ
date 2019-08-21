#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;
    vector<char> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<int> v[n];
    while(e-- > 0){
	    int x, y;
	    cin >> x >> y;
	    v[x].push_back(y);
	    v[y].push_back(x);
    }
    for(int i = 0; i < n; i++){
	    if(c[i] != '?')	continue;
	    bool used[26] = {};
	    for(int j : v[i]){
	        if(c[j] != '?')	used[c[j]-'a'] = true;
	    }
	    for(int j = 0; j < 26; j++){
	        if(!used[j]){
		        c[i] = (char)('a' + j);
		        break;
	        }
        }
    }
    for(int i = 0; i < n; i++)	cout << c[i];
    cout << endl;
    return 0;
}
