#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    int dp[h][w];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < w; i++)
        dp[0][i] = (mat[0][i] == '0');
    for (int i = 1; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (mat[i][j] == '0')
                dp[i][j] = dp[i - 1][j] + 1;
            else
                dp[i][j] = 0;
        }
    }

    int ans = -1;
    for (int i = 0; i < h; i++)
    {
        // pair<left end, height>
        stack<pair<int, int>> s;
        for (int j = 0; j < w; j++)
        {
            if (s.empty())
            {
                s.push({j, dp[i][j]});
            }
            else if (dp[i][j] > s.top().second)
            {
                s.push({j, dp[i][j]});
            }
            else if (dp[i][j] == s.top().second)
            {
                // do nothing.
            }
            else if (dp[i][j] < s.top().second)
            {
                int left;
                while (!s.empty() && dp[i][j] < s.top().second)
                {
                    pair<int, int> now = s.top();
                    s.pop();
                    // make rectangle
                    ans = max(ans, (j - now.first) * (now.second));
                    left = now.first;
                }
                s.push({left, dp[i][j]});
            }
        }

        while (!s.empty())
        {
            pair<int, int> now = s.top();
            s.pop();
            ans = max(ans, (w - now.first) * (now.second));
        }
    }

    cout << ans << endl;

    return 0;
}
