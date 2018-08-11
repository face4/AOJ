// ただのbrute-force
#include<iostream>
#include<vector>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;

        if(n == 0)  break;

        bool appear[n+1] = {};
        for(int i = 1; i < n; i++){
            appear[(i*i)%n] = true;
        }

        vector<int> p;
        for(int i = 0; i <= n; i++){
            if(appear[i])   p.push_back(i);
        }

        int len = p.size();
        int ans[(n-1)/2 + 1] = {};

        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                if(i == j)  continue;
                int diff = p[i] - p[j];
                if(diff < 0)        diff += n;
                if(diff > (n-1)/2)  diff = n - diff;
                ans[diff]++;
            }
        }

        for(int i = 1; i <= (n-1)/2; i++){
            cout << ans[i] << endl;
        }
    }

    return 0;
}