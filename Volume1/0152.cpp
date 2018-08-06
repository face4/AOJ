#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

bool comp(pair<int,int> x, pair<int,int> y){
    if(x.second != y.second)    return x.second > y.second;
    else                        return x.first < y.first;
}

int main(){
    int m;
    while(1){
        scanf("%d\n", &m);
        if(m == 0)  break;

        vector<pair<int,int>> v;
        
        for(int i = 0; i < m; i++){
            string x;
            getline(cin, x);
            stringstream ss;
            ss << x;
            int id, score = 0;
            ss >> id;
            int tmp, pos = 0, accum = 0, flame = 1;
            int bias[30] = {};
            bool first = true;
            while(flame < 10){
                ss >> tmp;
                score += tmp * (1 + bias[pos]);
                accum += tmp;
                if(first){
                    if(accum == 10){
                        bias[pos+1]++;
                        bias[pos+2]++;
                        accum = 0;
                        flame++;
                    }else{
                        first = false;
                    }
                }else{
                    if(accum == 10){
                        bias[pos+1]++;
                    }
                    first = true;
                    accum = 0;
                    flame++;
                }
                pos++;
            }

            while(ss >> tmp){
                score += tmp * (1 + bias[pos]);
                pos++;
            }    

            v.push_back({id, score});
        }

        sort(v.begin(), v.end(), comp);

        for(int i = 0; i < v.size(); i++){
            cout << v[i].first << " " << v[i].second << endl;
        }
    }
    return 0;
}