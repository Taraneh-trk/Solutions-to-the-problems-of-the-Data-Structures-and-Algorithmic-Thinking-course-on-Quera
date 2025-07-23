#include <iostream>
using namespace std;

const int MAXN = 1000 * 100 + 5;
const int MAXD = 1000 * 1000 + 5;

int n, q;
int c[MAXN], d[MAXN], dp[MAXD];

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < q; i++)
        cin >> d[i];

    for (int i = 0; i < n; i++)
        dp[c[i]]++;
    for (int i = MAXD - 1; i > 0; i--)
        dp[i - 1] += dp[i];

    for (int i = 0; i < q; i++)
        cout << n - dp[d[i]] << endl;
        
    return 0;
}
