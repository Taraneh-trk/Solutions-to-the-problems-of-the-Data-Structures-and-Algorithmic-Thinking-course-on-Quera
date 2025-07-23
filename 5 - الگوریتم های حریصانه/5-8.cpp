#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define S second
#define F first

bool compare(pair<ld, ld>& a, pair<ld, ld>& b) {
    return a.first / a.second < b.first / b.second;
}

int main()
{
    int n, V;
    cin >> n >> V;

    pair<ld, ld> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].F >> a[i].S;

    sort(a, a + n, compare);

    ld res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i].S <= V)
        {
            res += a[i].F;
            V -= a[i].S;
        }
        else
        {
            res += a[i].F * V / a[i].S;
            V = 0;
            break;
        }
    }

    cout << setprecision(3) << fixed << showpoint << res << endl;

    return 0;
}
