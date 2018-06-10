#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

static const int N = 1000;
static int dp[N + 1][N + 1];

int lcs(string x, string y)
{
    int m = x.length();
    int n = y.length();
    x = ' ' + x;
    y = ' ' + y;

    dp[0][0] = 0;
    for (int i = 1; i <= m; i++)
        dp[i][0] = 0;
    for (int j = 1; j <= n; j++)
        dp[0][j] = 0;

    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == y[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    int n;
    cin >> n;
    string x1, x2;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> x2;
        cout << lcs(x1, x2) << endl;
    }
    return 0;
}