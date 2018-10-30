#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> p;
    bool nonp[300001] = {};

    p.push_back(6);
    for(int i = 12; i < 300001; i += 6) nonp[i] = true;

    for(int i = 1; 7*i+1 < 300001; i++){
        if(!nonp[7*i+1]){
            p.push_back(7*i+1);
            for(int j = 14*i+2; j < 300001; j += 7*i+1) nonp[j] = true;
        }
        if(7*i+6 > 300000)  break;
        if(!nonp[7*i+6]){
            p.push_back(7*i+6);
            for(int j = 14*i+12; j < 300001; j += 7*i+6) nonp[j] = true;
        }
    }

    int n;
    while(cin >> n, n != 1){
        cout << n << ":";
        for(int x : p)  if(n % x == 0)  cout << " " << x;
        cout << endl;
    }

    return 0;
}