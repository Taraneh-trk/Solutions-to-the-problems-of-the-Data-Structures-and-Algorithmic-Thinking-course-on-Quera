#include <bits/stdc++.h>
using namespace std;

int solve(int deadLine[], int n)
{ /// n = length of array d
    sort(deadLine, deadLine + n);
    int currentTime = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentTime < deadLine[i])
        {                  /// we can do this task
            ans++;         /// do task
            currentTime++; /// task takes 1 minute
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n; /// n = number of tasks
    int deadLine[n];
    for (int i = 0; i < n; i++)
        cin >> deadLine[i];

    cout << solve(deadLine, n) << '\n';
    return 0;
}
