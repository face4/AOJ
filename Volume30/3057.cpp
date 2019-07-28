#include<iostream>
using namespace std;

// 解説を読んだ
// 各ポッキーが1 1 1 ... 1となった状態が負けなので、
// 全てのポッキーの長さを1減じたものに対するNimを考えればよい
// 長さxのポッキーに対するgrundy数は、観察を行うと
// (x-1)%(d+1)であることがわかる(実際に書き出せば明らか)

int main(){
    int n, d;
    cin >> n >> d;
    int nim = 0;
    while(n-- > 0){
        int x;  cin >> x;
        nim ^= (x-1)%(d+1);
    }
    cout << (nim==0 ? "Second" : "First") << endl;
    return 0;
}