#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
bool seen[MAXN];
string s[MAXN];

/**
greedy approach :
we always stay in one organization as long as we can
so if we have intel about (n-1) organization we should stay in other organization

if i is the first place where we have intel about all organization we need to be
at organization s[i] and sell first (i-1) intels to organization s[i]
now we are at organization s[i]
*/

int main()
{
    int n;
    cin >> n;
    cin.ignore(); /// need this line for sync getline & cin

    for (int i = 0; i < n; i++)
        getline(cin, s[i]);

    int q;
    cin >> q;
    cin.ignore(); /// need this line for sync getline & cin

    int ans = 0;
    for (int i = 0; i < q; i++)
    {
        string t;
        getline(cin, t);
        for (int j = 0; j < n; j++)
            if (t == s[j]) /// we see string t
                seen[j] = true;

        bool allTrue = true; /// if we saw all string : allTrue = true  else allTrue = false
        for (int j = 0; j < n; j++)
            if (!seen[j])
                allTrue = false;

        if (allTrue)
        {                                /// if we saw all strings
            fill(seen, seen + n, false); /// assume we didn't see any string
            ans++;                       /// we were on organization t now we go to somewhere else
        }

        for (int j = 0; j < n; j++)
            if (t == s[j]) /// now we only saw organization t
                seen[j] = true;
    }

    cout << ans << endl;
    return 0;
}
