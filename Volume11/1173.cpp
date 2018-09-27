#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    string str, t = "()[]";
    while(getline(cin,str) && str != "."){
        stack<char> s;
        bool judge = true;
        for(char x : str){
            if(!count(t.begin(), t.end(), x))    continue;

            if(s.empty() || x == '(' || x == '['){
                s.push(x);
            }else if(!s.empty() && (x == ')' && s.top() == '(') || (x == ']' && s.top() == '[')){
                s.pop();
            }else{
                judge = false;
                break;
            }
        }
        
        if(s.empty() && judge)  cout << "yes" << endl;
        else                    cout << "no" << endl;
    }
    return 0;
}