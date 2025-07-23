#include <bits/stdc++.h>
using namespace std;

long long ans;
const int MAX_N = 8;
bool row[MAX_N];
bool diag1[MAX_N * 2];
bool diag2[MAX_N * 2];

void kQueen(int n, int k, int col)
{
    if (col == n)
    { /// exit condition
        if (k == 0)
            ans++;
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (row[i])
            continue; /// there is a queen in this row
        if (diag1[i + col])
            continue; /// there is a queen(a,b) that i + col = a +b
        if (diag2[i - col + MAX_N])
            continue;                                            /// 0 <= i-col+MAX_N < 2*MAX_N : there is a queen(a,b) that i - col = a -b
        row[i] = diag1[i + col] = diag2[i - col + MAX_N] = true; /// change grid : put a queen in (col, i)
        kQueen(n, k - 1, col + 1);
        row[i] = diag1[i + col] = diag2[i - col + MAX_N] = false; /// undo last change
    }
    kQueen(n, k, col + 1); /// don't put any queen on this column
}

int main()
{
    int n, k;
    cin >> n >> k;

    kQueen(n, k, 0);
    cout << ans << endl;

    return 0;
}
