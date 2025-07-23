#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 10;
const long long INF = 1e18;

int n, m, a[MAXN][MAXN];
long long b[MAXN], dp[MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    long long ans = -INF; // A very small number
    for (int upperRow = 0; upperRow < n; upperRow++)
    {
        for (int column = 0; column < m; column++)
            b[column] = 0;
        // b[column] should be the sum of all
        // numbers in respective column
        // between "upperRow" and "lowerRow"
        for (int lowerRow = upperRow; lowerRow < n; lowerRow++)
        {
            for (int column = 0; column < m; column++)
                b[column] += a[lowerRow][column];
            dp[0] = 0;
            for (int i = 0; i < m; i++)
            {
                dp[i + 1] = max(dp[i] + b[i], b[i]);
                ans = max(ans, dp[i + 1]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}