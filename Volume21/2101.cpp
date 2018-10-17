// coding on smartphone
#include<iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n, n){
		if(n == 1){
			cout << "deficient number\n";
			continue;
		}
		int sum = 1;
		for(int i = 2; i*i <= n; i++){
			if(n % i) continue;
			sum += i + n/i;
			if(i*i == n) sum -= i;
		}
		
		if(sum < n) cout << "deficient number\n";
		else if(sum > n) cout << "abundant number\n";
		else cout << "perfect number\n";
	}
	return 0;
}
