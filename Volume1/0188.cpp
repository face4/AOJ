#include<iostream>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;

        if(n == 0)  break;

        int A[n];
        for(int i = 0; i < n; i++)  cin >> A[i];

        int x;
        cin >> x;
        int ans = 0;
        int r = n-1, l = 0;

        while(l <= r){
            ans++;
            int mid = (r+l)/2;
            if(A[mid] == x || l > r) break;
            else if(A[mid] < x) l = mid+1;
            else if(A[mid] > x) r = mid-1;
        }

        cout << ans << endl;
    }
    return 0;
}