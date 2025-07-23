#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 1;

int dp[MAXN][MAXN], par[MAXN][MAXN];

int main()
{
    string s, p;
    cin >> s >> p;
    // s and p are zero based strings
    for (int i = 0; i <= max(s.size(), p.size()); i++)
        dp[0][i] = dp[i][0] = 0;
    // filling the dp
    int n = s.size(), m = p.size();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                par[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                par[i][j] = 1;
            }

            if (s[i - 1] == p[j - 1] && dp[i][j] < dp[i - 1][j - 1] + 1)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                par[i][j] = 2;
            }
        }
    cout << dp[n][m] << '\n';

    // output the answer
    int curI = n, curJ = m;
    string answer = "";
    while (curI > 0 && curJ > 0)
    {
        if (par[curI][curJ] == 0)
            curI--;
        else if (par[curI][curJ] == 1)
            curJ--;
        else
        {
            answer = s[curI - 1] + answer;
            curI--;
            curJ--;
        }
    }
    cout << answer << '\n';
    
    return 0;
}
