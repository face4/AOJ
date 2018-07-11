// この貪欲解法は誤り.
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        
        if(n == 0)  break;
        
        vector<int> p, j;
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            p.push_back(x);
        }
        
        for(int i = 0; i < n-1; i++){
            cin >> x;
            j.push_back(x);
        }
        
        for(int i = 0; i < p.size()-1; i++){
            if(2*(p[i] + p[i+1]) < (p[i] + p[i+1] + j[i])){
                p[i] += p[i+1] + j[i];
                p.erase(p.begin() + i+1);
                i--;
            }
        }
        
        int ans = accumulate(p.begin(), p.end(), 0) * p.size();
        cout << ans << endl;
    }
}
