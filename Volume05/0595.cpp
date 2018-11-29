// coding on smartphone
#include<iostream>
using namespace std;

const int mod = 10007;

int main(){
	int n;
	string s;
	
	cin >> n >> s;
	
	int dp[1001][8] = {};
	dp[0][4] = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = 1; j < 8; j++){
			int f = 1;
			if(s[i] == 'O') f <<= 1;
			if(s[i] == 'J') f <<= 2;
			for(int k = 1; k < 8; k++){
				if( (j&k) == 0 || (k&f) == 0) continue;
				dp[i+1][k] = (dp[i+1][k]+dp[i][j])%mod;
			}
		}
	}
	
	int ans = 0;
	for(int k = 1; k < 8; k++){
		ans = (ans + dp[n][k])%mod;
	}
	
	cout << ans << endl;
	
	return 0;
}