#include<iostream>
using namespace std;

string cell[9] = {".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main(){
    int n;
    scanf("%d\n", &n);

    for(int i = 0; i < n; i++){
        string s;
        getline(cin,s);
        int len = s.length();
        for(int j = 0; j < len; j++){
            int cnt = 0;
            char x = s[j];
            if(x == '0')    continue;
            while(j < len && s[j] == x)    j++, cnt++;
            int tmplen = cell[x-'1'].length();
            cout << cell[x-'1'][(cnt-1+tmplen)%(tmplen)];
        }
        cout << endl;
    }
    return 0;
}