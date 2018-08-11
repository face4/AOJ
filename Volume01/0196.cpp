#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    char name;
    int win, lose;
    data(char n, int w, int l) : name(n), win(w), lose(l) {}
    bool operator<(const data other) const{
        if(win != other.win)    return win < other.win;
        else                    return lose > other.lose;
    }
};

int main(){
    while(1){
        int n;
        cin >> n;

        if(n == 0)  break;

        vector<data> result;
        char t;
        int r;

        for(int i = 0; i < n; i++){
            cin >> t;
            int w = 0, l = 0;
            for(int j = 0; j < n-1; j++){
                cin >> r;
                if(r == 0)  w++;
                if(r == 1)  l++;
            }
            result.push_back(data(t, w, l));
        }

        sort(result.rbegin(), result.rend());

        for(data d : result)    cout << d.name << endl;
    }
    return 0;
}