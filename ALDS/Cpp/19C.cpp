#include<iostream>
using namespace std;

#define MAX 2000000
#define INFTY 1<<30;

int H, A[MAX+1];

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

int extract(){
    int maxv;
    if(H < 1)   return -INFTY;

    maxv = A[1];
    A[1]= A[H--];
    maxHeapify(1);
    return maxv;
}

void heapIncreasseKey(int i, int key){
    if(key < A[i]) return;
    A[i] = key;
    while(i > 1 && A[i/2] < A[i]){
        swap(A[i/2], A[i]);
        i = i/2;
    }
}

void insert(int key){
    H++;
    A[H] = -INFTY;
    heapIncreasseKey(H, key);
}

int main(){
    int key;
    char com[10];

    while(1){
        cin >> com;
        if(com[0] == 'e' && com[1] == 'n')  break;

        if(com[0] == 'i'){
            cin >> key;
            insert(key); 
        }else{
            cout << extract() << endl;
        }
    }

    return 0;
}