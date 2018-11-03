#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, r, t;
    cin >> n;

    while(n-- > 0){
        cin >> r >> t;
        
        vector<int> ans;

        if(r % 100 == 0){
            ans.push_back(t/30*5 + r/100);
            if(t%30){
                ans.push_back((t/30+1)*5 + r/100);
            }
        }else{
            ans.push_back(t/30*5 + r/100);
            ans.push_back(t/30*5 + r/100 + 1);
            if(t%30){
                ans.push_back((t/30+1)*5 + r/100);
                ans.push_back((t/30+1)*5 + r/100 + 1);
            }
        }

        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i == ans.size()-1];
    }

    return 0;
}