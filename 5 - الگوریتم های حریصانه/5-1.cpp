#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    ll sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
        if (sum + a[i] <= k)
            sum += a[i], ans++;

    cout << ans << endl;
    return 0;
}