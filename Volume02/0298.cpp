#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> times;
    int n, h, m;
    cin >> n;
    while(n-- > 0){
        cin >> h >> m;
        times.insert(60*h + m);
    }
    cin >> n;
    while(n-- > 0){
        cin >> h >> m;
        times.insert(60*h + m);
    }
    
    bool first = true;
    for(set<int>::iterator it = times.begin(); it != times.end(); it++){
        if(first)   first = false;
        else        printf(" ");
        
        int x = *it;
        int a = x / 60;
        int b = x - 60*a;
        
        printf("%d:%02d", a, b);
    }
    printf("\n");
    
    return 0;
}
