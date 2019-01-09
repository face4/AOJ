#include<iostream>
using namespace std;

int main(){
    int n, k;
    while(cin >> n >> k, n+k){
        // O(n^3)
        int c[n];
        for(int i = 0; i < n; i++)  cin >> c[i];
        
        auto func = [&]() -> int {
            int t = 1;
            for(int i = 0; i < k; i++)  t *= c[i];
            int tmp = t;
            for(int i = k; i < n; i++){
                tmp /= c[i-k];
                tmp *= c[i];
                t = max(t, tmp);
            }
            return t;
        };

        int t = func();
        int s = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(c[i], c[j]);
                s = max(s, func());
                swap(c[i], c[j]);
            }
        }

        if(s >= t)   cout << s-t << endl;
        else        cout << "NO GAME" << endl;
    }
    return 0;
}