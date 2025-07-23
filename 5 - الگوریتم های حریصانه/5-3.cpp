#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int n, k, L;
    cin >> n >> k >> L;

    int d[n + 2];

    d[0] = 0;
    for (int i = 1; i < n + 1; i++)
        cin >> d[i];
    d[n + 1] = L;

    ll sum = 0;
    vector<int> ans;
    for (int i = 1; i < n + 2; i++)
        if (d[i] - d[i - 1] > k)
        {
            sum = -1;
            break;
        }
        else if (sum + d[i] - d[i - 1] > k)
        {
            sum = d[i] - d[i - 1];
            ans.push_back(i - 1);
        }
        else sum += d[i] - d[i - 1];

    if (sum == -1)
        cout << -1 << endl;
    else
    {
        cout << ans.size() << endl;
        for (int u : ans)
            cout << u << ' ';
        cout << endl;
    }

    return 0;
}