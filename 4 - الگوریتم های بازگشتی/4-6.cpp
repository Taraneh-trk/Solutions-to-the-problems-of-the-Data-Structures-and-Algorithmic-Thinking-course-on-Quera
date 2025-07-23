#include <bits/stdc++.h>
using namespace std;

int a[22];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i]; /// input

    long long ans = 1e19;
    /// (1<<n) = 2^n
    for (int mask = 0; mask < (1 << n); mask++)
    {
        long long sumC, sumB;
        sumC = sumB = 0; /// sumC = sum of values in C
        for (int i = 0; i < n; i++)
            if ((1 << i) & mask) /// a[i] is in C
                sumC += a[i];
            else /// a[i] is in B
                sumB += a[i];
        ans = min(ans, abs(sumC - sumB)); /// find new answer
    }
    cout << ans << endl;
}
