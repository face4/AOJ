#include <iostream>
using namespace std;

int n, m, q, x;
int A[20];

bool solve(int i, int m)
{
    if (m == 0)
        return true;
    if (i < 0)
        return false;

    bool ret = solve(i - 1, m - A[i]) || solve(i - 1, m);
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        if (solve(n - 1, x))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}