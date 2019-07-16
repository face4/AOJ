#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n, k;
    while(cin >> n >> k, n){
        string a[n];
        for(int i = 0; i < n; i++)  cin >> a[i];
        set<string> s;
        for(int i = 0; i < 1<<n; i++){
            vector<string> v;
            for(int j = 0; j < n; j++){
                if((i>>j)&1)    v.push_back(a[j]);
            }
            if(v.size() != k)   continue;
            sort(v.begin(), v.end());
            do{
                string t = "";
                for(string u : v)   t += u;
                s.insert(t);
            }while(next_permutation(v.begin(), v.end()));
        }
        cout << s.size() << endl;
    }
    return 0;
}