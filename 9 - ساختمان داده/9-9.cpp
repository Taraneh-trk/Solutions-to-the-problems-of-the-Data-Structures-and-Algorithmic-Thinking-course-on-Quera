#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;

    multiset<int> deadlines;
    for (int i = 0; i < n; i++)
    {
        while (!deadlines.empty() && *deadlines.begin() <= i)
            deadlines.erase(deadlines.begin());

        int size;
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            int x;
            cin >> x;
            deadlines.insert(x + i);
        }

        if (!deadlines.empty())
        {
            ans++;
            deadlines.erase(deadlines.begin());
        }
    }
    
    cout << ans << endl;
    return 0;
}
