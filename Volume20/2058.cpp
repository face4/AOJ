#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<vector<int>> v;
    vector<int> x(10);
    for(int i = 0; i < 10; i++) x[i] = i+1;
    do{
        int z = (x[0]+x[1]+x[2])%x[9];
        bool judge = true;
        for(int i = 0; i < 3; i++){
            judge &= (x[3*i]+x[3*i+1]+x[3*i+2])%x[9] == z;
            judge &= (x[i]+x[3+i]+x[6+i])%x[9] == z;
        }
        judge &= (x[0]+x[4]+x[8])%x[9] == z;
        judge &= (x[2]+x[4]+x[6])%x[9] == z;
        if(judge)   v.push_back(x);
    }while(next_permutation(x.begin(),x.end()));
    
    while(1){
        for(int i = 0; i < 10; i++) cin >> x[i];
        if(x[0] == -1)  break;
        int ans = 0;
        for(vector<int> y : v){
            bool judge = true;
            for(int i = 0; i < 10; i++){
                judge &= x[i]==0 || x[i]==y[i];
            }
            if(judge)   ans++;
        }
        cout << ans << endl;
    }

    return 0;
}