#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin >> n;

    int score[101] = {};
    map<int,int> res, grade;

    int a, b, c, d;
    for(int i = 0; i < n*(n-1)/2; i++){
        cin >> a >> b >> c >> d;
        a--; b--;
        if(c == d){
            score[a]++;
            score[b]++;
        }else if(c < d){
            score[b] += 3;
        }else if(c > d){
            score[a] += 3;
        }
    }

    for(int i = 0; i < n; i++)  res[score[i]]++;

    int now = 1;
    for(auto x = res.rbegin(); x != res.rend(); x++){
        grade[(*x).first] = now;
        now += (*x).second;
    }

    for(int i = 0; i < n; i++)  cout << grade[score[i]] << endl;

    return 0;
}