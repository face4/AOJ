#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    auto f = [](char c)->int{
        if(inRange(c, 'A', 'M'))    return 0;
        if(inRange(c, 'N', 'Z'))    return 1;
        if(inRange(c, 'a', 'm'))    return 2;
        if(inRange(c, 'n', 'z'))    return 3;
    };
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0, j = 0;
    for(char c : s){
        i += di[f(c)], j += dj[f(c)];
    }
    string ret = "";
    while(i > 0)    ret += "a", i--;
    while(i < 0)    ret += "n", i++;
    while(j > 0)    ret += "A", j--;
    while(j < 0)    ret += "N", j++;
    cout << ret.length() << endl;
    cout << ret << endl;
    return 0;
}
