#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    int p, d;
    data(int person, int dist) : p(person), d(dist) {}
    bool operator<(const data other) const{
        return d < other.d;
    }
};

int main(){
    while(1){
        int n;
        cin >> n;

        if(n == 0)  break;

        vector<data> score;
        int p, d1, d2;
        for(int i = 0; i < n; i++){
            cin >> p >> d1 >> d2;
            score.push_back(data(p, d1+d2));
        }

        sort(score.begin(), score.end());
        reverse(score.begin(), score.end());

        cout << score[0].p << " " << score[0].d << endl;
    }
    return 0;
}