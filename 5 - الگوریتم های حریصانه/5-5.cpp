#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100010;

pair<int, int> a[MAX_N];

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a, a + n);
    for (int i = 0; i < n; i++)
        if (k >= a[i].first)                   /// we can eat i-th fruit
            if (a[i].second > a[i].first)      /// we gain positive energy by eating this fruit
                k += a[i].second - a[i].first; /// eat -> lose a[i].first energy ans gain a[i].second
    cout << k << '\n';
}
