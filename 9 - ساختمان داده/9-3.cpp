#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int n, a[maxn], counter[maxn];
bool isValid[maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    // a[i] starts with zero and is 0 based!
    for (int i = 0; i < n; i++)
        counter[a[i]]++;

    queue<int> Q;
    int numberOfValids = n;
    for (int i = 0; i < n; i++)
    {
        isValid[i] = true;
        if (counter[i] == 0)
            Q.push(i);
    }

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        isValid[x] = false; // mark as deleted
        counter[a[x]]--;
        numberOfValids--;
        if (counter[a[x]] == 0)
            Q.push(a[x]);
    }

    cout << numberOfValids << endl;
    for (int i = 0; i < n; i++) // output is 1 based
        if (isValid[i])
            cout << i + 1 << ' ';
    cout << '\n';

    return 0;
}
