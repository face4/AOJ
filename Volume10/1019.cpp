#include<iostream>
using namespace std;

int main(){
    int n, k, b;
    while(cin >> n >> k){
        if(n + k == 0)  break;

        int s[k];
        for(int i = 0; i < k; i++)  cin >> s[i];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                cin >> b;
                s[j] -= b;
            }
        }

        bool judge = true;
        for(int i = 0; i < k; i++)  if(s[i] < 0)    judge = false;

        if(judge)   cout << "Yes" << endl;
        else        cout << "No" << endl;
    }
    return 0;
}