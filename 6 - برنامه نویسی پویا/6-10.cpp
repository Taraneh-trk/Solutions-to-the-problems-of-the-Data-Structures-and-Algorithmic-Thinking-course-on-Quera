#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300 + 1;
const long long INF = 1e18;

int n, a[MAXN];
long long dp[MAXN][MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n + 1; i++)
        cin >> a[i];

    for (int sizeOfSegment = 2; sizeOfSegment <= n; sizeOfSegment++)
        for (int l = 0; l + sizeOfSegment <= n; l++)
        {
            int r = l + sizeOfSegment - 1;
            dp[l][r] = INF;
            for (int i = l; i < r; i++)
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + 1ll * a[l] * a[i + 1] * a[r + 1]);
        }
    cout << dp[0][n - 1] << endl;

    return 0;
}
