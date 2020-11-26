#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

void f(int &score, string &s, bool &eleven){
    int ace = 0;
    score = 0;
    eleven = false;
    for(char c : s){
        if(inRange(c, '2', '9'))    score += c-'0';
        else if(c == 'A')           ace++, score++;
        else                        score += 10;
    }
    while(ace--){
        if(score+10 <= 21)  eleven = true, score += 10;
    }
}

int main(){
    int q;
    cin >> q;
    while(q--){
        char a, b;
        cin >> a >> b;
        string s = "";
        s += a; s += b;
        int score;
        bool ele;
        f(score, s, ele);
        char c[8];
        for(int i = 0; i < 8; i++)  cin >> c[i];
        if(score == 21){
            cout << "blackjack" << endl;
            continue;
        }
        for(int i = 0; i < 8; i++){
            if(score <= 16 || (score==17 && ele)){
                s += c[i];
                f(score, s, ele);
            }else{
                break;
            }
        }
        if(score > 21)  cout << "bust" << endl;
        else            cout << score << endl;
    }
    return 0;
}