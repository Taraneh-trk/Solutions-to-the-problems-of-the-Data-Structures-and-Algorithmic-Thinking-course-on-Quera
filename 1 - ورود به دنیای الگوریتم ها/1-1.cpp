#include <iostream>
using namespace std;

const int MAXN = 1000;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;

        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (a[j] < x)
                cnt++;

        cout << cnt << '\n';
    }

    return 0;
}