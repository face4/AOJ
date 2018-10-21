// coding on smartphone
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	vector<int> p;
	bool nonp[50000] = {};
	for(int i = 2; i < 50000; i++){
		if(nonp[i]) continue;
		p.push_back(i);
		for(int j = i+i; j < 50000; j+=i) nonp[j] = true;
	}
	
	int m, a, b;
	while(cin >> m >> a >> b, m+a+b){
		int ansa = 0, answ, ansh;
		for(int i = 0; i < p.size(); i++){
			if(p[i] > sqrt(m)) break;
			int x = min(p[i]*b/a, m/p[i]);
			int h = *(upper_bound(p.begin(), p.end(), x) - 1);
			if(p[i]*h > ansa){
				ansa = p[i]*h;
				answ = p[i];
				ansh = h;
			}
		}
		
		cout << answ << " " << ansh << endl;
	}
	
	return 0;
}
