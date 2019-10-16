#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main(){
    map<char,int> plus, minus;
    plus['('] = 0;  minus[')'] = 0;
    plus['{'] = 1;  minus['}'] = 1;
    plus['['] = 2;  minus[']'] = 2;

    int p, q;
    while(cin >> p >> q, p+q){
        vector<vector<double>> v;
        v.push_back(vector<double>(4, 0));
        for(int i = 0; i < p; i++){
            string s;   cin >> s;
            s += "@";   // sentinel
            int pos = 0;
            while(s[pos] == '.')    pos++;
            v[i][3] = pos;
            vector<double> now = v.back();
            while(pos < s.length()){
                if(plus.count(s[pos]))  now[plus[s[pos]]]++;
                if(minus.count(s[pos]))  now[minus[s[pos]]]--;
                pos++;
            }
            if(i != p-1)    v.push_back(now);
        }

        vector<int> x, y, z;
        for(int i = 1; i <= 20; i++){
            for(int j = 1; j <= 20; j++){
                for(int k = 1; k <= 20; k++){
                    bool valid = true;
                    for(int l = 0; l < p; l++){
                        valid &= i*v[l][0]+j*v[l][1]+k*v[l][2]==v[l][3];
                    }
                    if(!valid)  continue;
                    x.push_back(i);
                    y.push_back(j);
                    z.push_back(k);
                }
            }
        }

        vector<int> target(3,0);
        while(q-- > 0){
            string s;   cin >> s;
            set<int> num;
            for(int i = 0; i < x.size(); i++){
                num.insert(x[i]*target[0]+y[i]*target[1]+z[i]*target[2]);
            }
            cout << (num.size()!=1 ? -1 : *(num.begin())) << " \n"[q==0];
            for(char c : s){
                if(plus.count(c))  target[plus[c]]++;
                if(minus.count(c))  target[minus[c]]--;
            }
        }

    }
    return 0;
}