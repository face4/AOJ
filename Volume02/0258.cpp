#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        n++;
        int h[n];
        for(int i = 0; i < n; i++)  cin >> h[i];
        
        for(int i = 0; i < n; i++){
            vector<int> now;
            int j;
            for(j = 0; j < n; j++)  if(i != j)  now.push_back(h[j]);
            
            int diff = now[1] - now[0];
            for(j = 2; j < n-1; j++){
                if(now[j]-now[j-1] != diff) break;
            }
            
            if(j == n-1){
                cout << h[i] << endl;
                break;
            }
        }
    }
    return 0;
}
