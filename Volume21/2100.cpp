// coding on smartphone
#include<iostream>
using namespace std;

int main(){
	int t, a[2];
	cin >> t;
	
	while(t-- > 0){
		int n, ma = 0, mi = 0;
		cin >> n >> a[1];
		for(int i = 0; i < n-1; i++){
			cin >> a[i%2];
			ma = max(ma, a[i%2]-a[1-(i%2)]);
			mi = min(mi, a[i%2]-a[1-(i%2)]);
		}
		cout << ma << " " << -mi << endl;
	}
	
	return 0;
}
