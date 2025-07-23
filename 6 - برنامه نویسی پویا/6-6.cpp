#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 10;
const long long INF = 1e18;

int n, m;
int a[MAXN][MAXN], par[MAXN][MAXN];
long long dp[MAXN][MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    // all elements are 0'based meaning we must go from (n-1,0) to (0,n-1)
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == n - 1 && j == 0)
            { // the base of the dp
                dp[i][j] = a[i][j];
                continue;
            }
            // update from two directions
            long long pathFromDown = -INF; // a very small number
            long long pathFromLeft = -INF;
            if (i != n - 1)
                pathFromDown = dp[i + 1][j];
            if (j != 0)
                pathFromLeft = dp[i][j - 1];
            if (pathFromLeft > pathFromDown)
            {
                par[i][j] = 0;
                dp[i][j] = pathFromLeft + a[i][j];
            }
            else
            {
                par[i][j] = 1;
                dp[i][j] = pathFromDown + a[i][j];
            }
        }
    }

    cout << dp[0][m - 1] << '\n';

    // Make the path from par[i][j]
    string outputPath = "";
    int currentRow = 0, currentColumn = m - 1;
    for (int i = 0; i < n + m - 2; i++)
    {
        if (par[currentRow][currentColumn] == 0)
        {
            currentColumn--;
            outputPath = 'R' + outputPath;
        }
        else
        {
            currentRow++;
            outputPath = 'U' + outputPath;
        }
    }
    cout << outputPath << '\n';

    return 0;
}
