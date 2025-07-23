#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
const int MAXM = 1e6 + 10;

int n, len[MAXN], val, a[MAXN][MAXN];
bool mark[MAXM];

/*\
 * calculate the number of ways to choose numbers from
 * sequence 'r' to 'n-1' so that it doesn't conflict with
 * the elements currently chosen
\*/

int backtrack(int r)
{
    if (r == n) // reached the last row and all numbers are chosen
        return 1;

    int ret = 0;
    for (int i = 0; i < len[r]; i++)
    {
        if (!mark[a[r][i]])
        {
            mark[a[r][i]] = true;
            ret += backtrack(r + 1);
            mark[a[r][i]] = false;
        }
    }

    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> len[i];
        for (int j = 0; j < len[i]; j++)
            cin >> a[i][j];
    }

    cout << backtrack(0) << '\n';
    return 0;
}
