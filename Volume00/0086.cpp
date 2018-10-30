// coding on smartphone
#include<iostream>
using namespace std;

int main(){
	int a, b;
	while(cin >> a >> b){
		int deg[101] = {};
		deg[a]++, deg[b]++;
		while(cin >> a >> b, a+b) deg[a]++, deg[b]++;
		bool judge = deg[1]%2 == 1 && deg[2]%2 == 1;
		for(int i = 3; i < 51; i++) if(deg[i]%2) judge = false;
		if(judge) cout << "OK" << endl;
		else      cout << "NG" << endl;
	}
	return 0;
}
