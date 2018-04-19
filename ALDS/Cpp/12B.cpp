#include <iostream>
using namespace std;

int selectionSort(int A[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minj = i;
        int j;
        for (j = i; j < n; j++)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }

        if (minj != i)
        {
            swap(A[minj], A[i]);
            count++;
        }
    }

    return count;
}

int main()
{
    int A[100], n, count;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    count = selectionSort(A, n);
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}