#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld power(ld a, int b)
{
    if (b == 0)
        return (ld)1;
    ld x = power(a, b / 2); // x will be equal to a ^ (b/2)
    x *= x;                 // x is equal to a^(b - b%2)
    if (b & 1)
        x *= a; // now x is a^b
    return x;
}

int main()
{
    ld a;
    cin >> a;
    int b;
    cin >> b;

    cout << fixed << setprecision(3); // for writing with exactly 3 digits.
    cout << power(a, b) << '\n';

    return 0;
}