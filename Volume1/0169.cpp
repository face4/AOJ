#include<iostream>
#include<sstream>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        if(s == "0")    break;

        int sum = 0;
        int one = 0;

        stringstream ss(s);
        int c;
        while(ss >> c){
            if(c == 1)  one++;
            if(c > 10)  c = 10;
            sum += c;
        }

        if(sum > 21){
            sum = 0;
        }else if(one > 0){
            while(one > 0 && sum+10 <= 21){
                sum += 10;
                one--;
            }
        }

        cout << sum << endl;
    }
    return 0;
}