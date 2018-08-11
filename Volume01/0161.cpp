#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    int number, min;
    data(int n, int m) : number(n), min(m){}

    bool operator<(const data other) const {
        return min < other.min;
    }
};

int main(){
    while(true){
        int n, id, m, s;
        cin >> n;

        if(n == 0)  break;

        vector<data> table;
        for(int i = 0; i < n; i++){
            cin >> id;
            int minutes = 0;
            for(int j = 0; j < 4; j++){
                cin >> m >> s;
                minutes += 60*m+s;
            }
            table.push_back(data(id, minutes));
        }

        sort(table.begin(), table.end());

        cout << table[0].number << endl;
        cout << table[1].number << endl;
        cout << table[n-2].number << endl;
    }
}