#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int M = a[(n - 1) / 2];
    long long int ans = 0;

    for (int i = 0; i < n; i++)
        ans += abs(a[i] - M);

    cout << M << ' ' << ans << '\n';

    return 0;
}