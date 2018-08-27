#include<iostream>
#include<algorithm>
using namespace std;

int j, y;

// あり得る得点状況なら0、さらにそれが終着点ならば1、あり得ないなら2
int isFinish(string s){
    int a = count(s.begin(), s.end(), 'A');
    int b = count(s.begin(), s.end(), 'B');

    // 与えられた得点状況に達した場合
    if(a == j && b == y)    return 1;
    
    // ルール上あり得ない状況に達した場合
    bool base = a <= j && b <= y;
    if(!base)   return 2;

    // 与えられた得点状況には達していないが試合が終わってしまった場合
    if(min(a,b) <= 3 && max(a,b) == 5)  return 2;
    if(max(a,b) == 6)   return 2;
    if(a == b && a == 5)    return 2;

    return 0;
}

void dfs(string s){
    int x = isFinish(s);
    if(x == 0){
        if(isFinish(s+"A") <= 1)    dfs(s+"A");
        if(isFinish(s+"B") <= 1)    dfs(s+"B");
    }else if(x == 1){
        cout << s << endl;
        return;
    }
}

int main(){
    cin >> j >> y;
    dfs("");
    return 0;
}