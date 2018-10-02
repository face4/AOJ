#include<iostream>
using namespace std;

struct rect{
    int h, w;
    rect(int h, int w) : h(h), w(w) {}
    bool operator <(const rect other) const{
        if(h*h + w*w == other.h*other.h+other.w*other.w){
            return h < other.h;
        }else{
            return h*h+w*w < other.h*other.h+other.w*other.w;
        }
    }
};

int main(){
    int H, W;
    while(cin >> H >> W, H+W){
        rect base(H, W);
        rect ans(300,300);
        for(int h = 1; h <= 150; h++){
            for(int w = h+1; w <= 150; w++){
                if(h == H && w == W)    continue;
                rect now(h,w);
                if(base < now && now < ans) ans = now;
            }
        }
        cout << ans.h << " " << ans.w << endl;
    }
    return 0;
}