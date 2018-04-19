#include <iostream>
using namespace std;
int A[100], n, v, j;

void print()
{
    for (j = 0; j < n; j++)
    {
        cout << (j == 0 ? "" : " ") << A[j];
    }
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    print();
    for (int i = 1; i < n; i++)
    {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print();
    }
    return 0;
}