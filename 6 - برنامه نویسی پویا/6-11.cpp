#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int dp[n], par[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        par[i] = -1;
        for (int j = 0; j < i; j++)
            if (s[j] < s[i] and dp[i] <= dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
    }

    int ans = max_element(dp, dp + n) - dp;
    vector<int> nums;
    while (ans != -1)
    {
        nums.push_back(s[ans]);
        ans = par[ans];
    }

    cout << nums.size() << endl;

    reverse(nums.begin(), nums.end());
    for (int u : nums)
        cout << u << ' ';
    cout << endl;

    return 0;
}
