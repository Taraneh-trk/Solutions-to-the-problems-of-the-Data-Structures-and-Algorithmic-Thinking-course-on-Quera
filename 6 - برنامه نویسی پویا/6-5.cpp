#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 10, MOD = 1e9 + 7;

int c[MAXN][MAXN];

int main()
{
    // Preprocess Phase:
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }

    // Answering queries:
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << c[a][b] << '\n';
    }
    
    return 0;
}
