#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, r;
    while(cin >> n >> r){
        vector<int> v(n);
        for(int i = 0; i < n; i++)  v[i] = i;
        while(r-- > 0){
            int c;  cin >> c;
            vector<int> next(n);
            int apos = n/2, bpos = 0, cur = 0;
            while(apos < n || bpos < n/2){
                for(int i = 0; i < c && apos < n; i++){
                    next[cur++] = v[apos++];
                }
                for(int i = 0; i < c && bpos < n/2; i++){
                    next[cur++] = v[bpos++];
                }
            }
            v = next;
        }
        cout << v[n-1] << endl;
    }
    return 0;
}