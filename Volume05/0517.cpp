#include<iostream>
using namespace std;

bool exist[100001];
int n, k;
bool zero = false;

int main(){
    while(cin >> n >> k){
        if(n + k == 0)  break;

        for(int i = 0; i < 100001; i++) exist[i] = false;

        int x;
        for(int i = 0; i < k; i++){
            cin >> x;
            exist[x] = true;
        }

        int beforeEnd = -2, beforeLength = 0;
        int ans = 0;
        for(int i = 1; i < 100001; i++){
            if(exist[i]){
                int start = i;
                while(i+1 < 100001 && exist[i+1]){
                    i++;
                }
                int tmpans = i-start+1;
                
                if(start-2 == beforeEnd && exist[0]){
                    tmpans += beforeLength+1; 
                }

                ans = max(ans, tmpans);
                beforeEnd = i;
                beforeLength = i-start+1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}