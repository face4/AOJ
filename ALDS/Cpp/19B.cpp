#include<iostream>
using namespace std;

int A[500001];
int H;

void maxHeapify(int i){
    int l = i*2;
    int r = i*2+1;
    int largest;
    
    if(l <= H && A[l] > A[i])   largest = l;
    else                        largest = i;
    if(r <= H && A[r] > A[largest]) largest = r;
    
    if(largest != i){
        swap(A[largest], A[i]);
        maxHeapify(largest);
    }
}

int main(){
    cin >> H;
    for(int i = 1; i <= H; i++) cin >> A[i];
    
    for(int i = H/2; i >= 1; i--){
        maxHeapify(i);
    }
    
    for(int i = 1; i <= H; i++){
        cout << " " << A[i];
    }
    cout << endl;
    
    return 0;
}
