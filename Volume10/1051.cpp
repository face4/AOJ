#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<int> v(n);
        for(int i = 0; i < n; i++)  cin >> v[i];
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++){
            if(i)   cout << " ";
            int j = i;
            while(j+1 < n && v[j+1]-v[j] == 1)  j++;
            if(i != j)  cout << v[i] << "-" << v[j];
            else        cout << v[i];
            i = j;
        }
        cout << endl;
    }
    return 0;
}