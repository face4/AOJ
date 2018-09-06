#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n), n){
        map<int,int> m;
        int a;
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            m[a]++;
        }

        string res = "NO COLOR";
        for(auto p : m) if(p.second > n/2)  res = to_string(p.first);
        printf("%s\n", res.c_str());
    }
    return 0;
}