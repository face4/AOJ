#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

#define f s.insert(a+b), s.insert(b+a);

int main(){
    int m;
    cin >> m;

    while(m-- > 0){
        string str;
        cin >> str;
        set<string> s;
        for(int i = 1; i < str.length(); i++){
            string a = str.substr(0,i), b = str.substr(i);
            f
            reverse(a.begin(), a.end());
            f
            reverse(b.begin(), b.end());
            f
            reverse(a.begin(), a.end());
            f
        }

        cout << s.size() << endl;
    }
    return 0;
}