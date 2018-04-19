#include<iostream>
using namespace std;

int A[100000], n;
int binarySearch(int key){
    int left = 0;
    int right = n;
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(A[mid] == key){
            return 1; // 1 -- true
        }
        if(A[mid] < key){
            left = mid + 1;
        }else if(A[mid] > key){
            right = mid;
        }
    }
    return 0; // 0 -- false
}

int main(){
    int i, q, key, sum = 0;
    cin >> n;
    for(i = 0; i < n; i++)  cin >> A[i];

    cin >> q;
    for(i = 0; i < q; i++){
        cin >> key;
        if(binarySearch(key)) sum++;
    }

    cout << sum << endl;
    return 0;
}