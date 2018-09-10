#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        stack<pair<int,int>> s;
        int c;
        cin >> c;
        int nowc = c, nowcnt = 1;
        for(int i = 2; i <= n; i++){
            cin >> c;
            if(nowc != c){
                if(i%2 == 1){
                    s.push({nowc, nowcnt});
                    nowc = c;
                    nowcnt = 1;
                }else{
                    nowc = c;
                    nowcnt++;
                    if(!s.empty()){
                        pair<int,int> p = s.top(); s.pop();
                        nowcnt += p.second;
                    }
                }
            }else{
                nowcnt++;
            }
        }
        s.push({nowc, nowcnt});

        int white = 0;
        while(!s.empty()){
            pair<int,int> p = s.top();  s.pop();
            if(p.first == 0)    white += p.second;
        }
        cout << white << endl;
    }
    return 0;
}