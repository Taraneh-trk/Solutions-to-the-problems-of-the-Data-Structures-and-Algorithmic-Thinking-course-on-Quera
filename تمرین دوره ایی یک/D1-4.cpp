// quera solution
#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 1001; 
int n, p[maxn];

// Function to calculate a^b using recursion and exponentiation by squaring
int power(int a, int b) {
    if (b == 0)
        return 1;
    int ret = power(a, b >> 1); // Compute a^(b//2)
    ret = ret * ret; // Square the result
    if (b & 1) 
        ret = ret * a;
    return ret;
}

// Function to find the number of ways to express x using powers up to max
int solve(int x, int max) {
    if (max < 0)
        return 0;
    if (x == 0)
        return 1;

    int ret = 0;
    if (p[max] <= x)
        ret += solve(x - p[max], max - 1); // Include p[max] in the sum
    if (max >= 2)
        ret += solve(x, max - 1); // Do not include p[max] in the sum

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x;
    cin >> x >> n;

    // Compute the powers of integers from 0 to maxn-1 raised to the power n
    for (int i = 0; i < maxn; i++)
        p[i] = power(i, n);

    // Calculate and print the number of ways to express x
    cout << solve(x, sqrt(x) + 2) << endl;
    return 0;
}

// my solution
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// ll x, n;
// vector<ll> powers; 
// ll dp[1001][1001]; 

// ll solve(ll target, ll idx) {
//     if (target == 0) return 1; 
//     if (target < 0 || idx >= (int)powers.size()) return 0;

//     if (dp[target][idx] != -1) return dp[target][idx];


//     ll res = solve(target - powers[idx], idx +1) + solve(target, idx +1);
//     dp[target][idx] = res;
//     return res;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> x >> n;

   
//     for (ll i = 1; ; i++) {
//         ll val = pow(i, n);
//         if (val > x) break;
//         powers.push_back(val);
//     }

//     memset(dp, -1, sizeof(dp));

//     cout << solve(x, 0) << '\n';

//     return 0;
// }
