#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

long long n, k, a[MAXN], b[MAXN];

long long calc(long long x)
{
    long long ret = 0;
    for (int i = 0; i < n; i++)
        ret += abs(a[i] - (x + k * i));
    return ret;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - i * k;
    }
    
    sort(b, b + n);
    cout << min(calc(b[n / 2]), calc(b[(n + 1) / 2]));
    return 0;
}
