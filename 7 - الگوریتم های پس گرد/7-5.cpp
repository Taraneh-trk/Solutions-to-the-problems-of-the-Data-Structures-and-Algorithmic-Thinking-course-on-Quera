#include <bits/stdc++.h>
using namespace std;

int arr[10][10] = {0};
int N;

int recur(int i, int j, int k) /// return number of cells we can reach in k step from cell (i,j)
{
    if (i < 0 || i > N - 1 || j < 0 | j > N - 1 || k < 0)
        return 0; /// not valid
    if (k == 0)
    {                  /// exit condition
        if (arr[i][j]) /// we count this cell before
            return 0;
        arr[i][j] = 1; /// we count this cell now
        return 1;
    }
    int t = 0;
    /// go to 8 cell that we can reach
    t += recur(i - 2, j + 1, k - 1) + recur(i - 2, j - 1, k - 1) + recur(i + 2, j - 1, k - 1) + recur(i + 2, j + 1, k - 1) +
         recur(i - 1, j + 2, k - 1) + recur(i + 1, j + 2, k - 1) + recur(i - 1, j - 2, k - 1) + recur(i + 1, j - 2, k - 1); /// recursive
    return t;
}

int main()
{
    int k;
    cin >> N >> k;

    int ans = recur(0, 0, k);
    cout << ans;

    return 0;
}
