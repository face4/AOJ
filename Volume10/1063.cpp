#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

struct data{
    data(){}
    string name;
    int start;
    bool operator<(const data other) const{
        return start < other.start;
    }
};

int main(){
    int n;
    while(cin >> n, n){
        bool t[60*24*8] = {};
        data d[n];
        int a, b;
        for(int i = 0; i < n; i++){
            cin >> d[i].name >> a >> b;
            d[i].start = 60*24*a + b/100*60 + b%100;
        }
        sort(d, d+n);
        
        map<string,int> m;
        for(int i = 0; i < n; i++)  m[d[i].name] = i;

        int p;
        cin >> p;
        
        string imp;
        bool valid = true;
        
        for(int i = 0; i < p; i++){
            cin >> imp;
            for(int j = 0; j < 30; j++){
                if(t[d[m[imp]].start+j])   valid = false;
                t[d[m[imp]].start+j] = true;
            }
        }

        if(!valid){
            cout << -1 << endl;
            continue;
        }

        int ans = p;
        for(int i = 0; i < n; i++){
            bool judge = true;
            for(int j = 0; j < 30; j++){
                if(t[d[i].start+j])   judge = false;
            }
            if(!judge)  continue;
            for(int j = 0; j < 30; j++){
                t[d[i].start+j] = true;
            }
            ans++;
        }

        cout << ans << endl;
    }
    return 0;
}