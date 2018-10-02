#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string a;
    int l;
    while(cin >> a >> l, l){
        while(a.length() != l) a = "0"+a;
        
        int arr[l];
        for(int i = 0; i < l; i++)  arr[i] = a[i]-'0';

        map<int,int> m;
        m[stoi(a)] = 0;

        int ansj, ansai, ansdiff, step = 1;
        while(1){
            sort(arr, arr+l);
            int less = 0, more = 0;
            for(int i = 0; i < l; i++){
                less = less*10 + arr[i];
                more = more*10 + arr[l-1-i];
            }
            int next = more-less;
            if(m.count(next)){
                ansj = m[next], ansai = next, ansdiff = step-ansj;
                break;
            }
            m[next] = step;
            int pos = 0;
            while(next > 0) arr[pos] = next%10, pos++, next /= 10;
            while(pos < l)  arr[pos] = 0, pos++;
            step++;
        }

        cout << ansj << " " << ansai << " " << ansdiff << endl;
    }
    return 0;
}