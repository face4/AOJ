#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    multiset<int> pos;
    while(q-- > 0){
        string s;
        int x;
        cin >> s >> x;
        if(s[0] == 'A'){
            pos.insert(upper_bound(b.begin(),b.end(),a[--x])-b.begin()-1);
        }else if(s[0] == 'R'){
            pos.erase(pos.find(upper_bound(b.begin(),b.end(),a[--x])-b.begin()-1));
        }else if(s[0] == 'C'){
            int ng = pos.size()==0 ? n : n-1-*(pos.rbegin());
            if(ng > x){
                cout << "NA" << endl;
                continue;
            }
            int l = -1, r = 1000000000;
            while(r-l > 1){
                int mid = (l+r)/2, tmpng = ng, bef = 0;
                for(auto it = pos.begin(); it != pos.end(); it++){
                    tmpng += max(0, (int)(lower_bound(b.begin(),b.end(),b[*it]-mid)-b.begin())-bef);
                    bef = *it+1;
                }
                if(tmpng <= x)  r = mid;
                else            l = mid;
            }
            cout << r << endl;
        }
    }
    return 0;
}
