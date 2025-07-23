#include <bits/stdc++.h>
using namespace std;

int A[10];

void f(int n, int x)
{
    if (x == n)
    { /// exit condition
        for (int i = 0; i < n; i++)
            cout << A[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        A[x] = i; /// set value of A[x] and call f(n, x+1) to set values of A[x+1] , ... A[n-1]
        f(n, x + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    f(n, 0);
}
