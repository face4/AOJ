#include<cstdio>
using namespace std;

struct Card{char suit, value;};

void bubble(struct Card A[], int N){
    for(int i = 0; i < N; i++){
        for(int j = N-1; j > i; j--){
            if(A[j].value < A[j-1].value){
                Card tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
            }
        }
    }
}

void selection(struct Card A[], int N){
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[minj].value > A[j].value){
                minj = j;
            }
        }
        Card tmp = A[minj];
        A[minj] = A[i];
        A[i] = tmp;
    }
}

void print(struct Card A[], int N){
    for(int i = 0; i < N; i++){
        if(i)   printf(" ");
        printf("%c%c", A[i].suit, A[i].value);
    }
    printf("\n");
}

bool isStable(struct Card C1[], struct Card C2[], int N){
    for(int i = 0; i < N; i++){
        if(C1[i].suit != C2[i].suit) return false;
    }
    return true;
}

int main(){
    Card C1[100], C2[100];
    int N;
    char buf[3];

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", buf);
        C1[i].suit = buf[0];
        C1[i].value = buf[1];
    }

    for(int i = 0; i < N; i++){
        C2[i] = C1[i];
    }

    bubble(C1, N);
    selection(C2, N);

    print(C1, N);
    printf("Stable\n");

    print(C2, N);
    if(isStable(C1, C2, N)){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }

    return 0;
}