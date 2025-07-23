#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000010;

int x[MAX_N];

int eatCandies(int c, int x[], int n)
{                               /// n = length of x
    sort(x, x + n);             /// x[] = 1 2 3 (increasing)
    reverse(x, x + n);          /// x[] = 3 2 1 (decreasing)
    for (int i = 0; i < n; i++) /// erase x[i] from board
        c -= min(c, max(0, x[i] - c));
    return c;
}

int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout << eatCandies(c, x, n) << '\n';
}
