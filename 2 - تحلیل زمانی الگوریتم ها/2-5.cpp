#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n - i; j++) {
            int k = n - i - j;
            if (i + j > k && k >= j)
                answer++;
        }
    cout << answer << '\n';
    return 0;
}
