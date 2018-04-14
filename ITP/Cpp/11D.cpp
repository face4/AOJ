#include <stdio.h>

using namespace std;

int main()
{
    int s;
    scanf("%d", &s);
    printf("%d:", s / 3600);
    s %= 3600;
    printf("%d:%d\n", s / 60, s % 60);
    return 0;
}