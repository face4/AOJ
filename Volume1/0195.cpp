#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    char name;
    int sell;
    data(char n, int s) : name(n), sell(s) {}
    bool operator<(const data other) const{
        return sell < other.sell;
    }
};

int main(){
    while(1){
        int a, b;
        cin >> a >> b;
        if(a + b == 0)  break;

        vector<data> res;
        res.push_back(data('A', a+b));

        for(int i = 1; i < 5; i++){
            cin >> a >> b;
            res.push_back(data((char)('A'+i), a+b));
        }

        sort(res.rbegin(), res.rend());

        cout << res[0].name << " " << res[0].sell << endl;
    }
    return 0;
}