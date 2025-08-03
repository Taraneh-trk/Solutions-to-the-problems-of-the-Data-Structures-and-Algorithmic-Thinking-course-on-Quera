// solution 1
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000010;
const int LOG_MAX_N = 21; // 2^(LOG_MAX_N-1) >= MAX_N
const int INF = 1000000000;
int a[MAX_N];
int rmq[LOG_MAX_N][MAX_N];

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        rmq[0][i] = a[i];
    }

    for (int k = 1; k < LOG_MAX_N; k++)
        for (int i = 0; i < n; i++)
            if (i + (1 << (k - 1)) < n)
                rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
            else
                rmq[k][i] = rmq[k - 1][i];

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        int ans = INF;
        int cur = l;
        for (int k = 0; k < LOG_MAX_N; k++)
            if ((1 << k) & (r - l + 1))
            {
                ans = min(ans, rmq[k][cur]);
                cur += (1 << k);
            }
        cout << ans << endl;
    }
    
    return 0;
}


// solution 2
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<ll, ll>> in(q);
    for (ll i = 0; i < q; i++) {
        cin >> in[i].first >> in[i].second;
    }

    vector<ll> p_2(n + 1);
    p_2[0] = 0;
    for (ll i = 1; i <= n; i++) {
        p_2[i] = (ll)log2(i);
    }

    int max_k = p_2[n] + 1;
    vector<vector<ll>> rmq(max_k, vector<ll>(n));
    for (ll i = 0; i < n; i++) {
        rmq[0][i] = a[i];
    }
    for (int k = 1; k < max_k; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
        }
    }

    for (ll i = 0; i < q; i++) {
        ll l = in[i].first;
        ll r = in[i].second;
        ll len = r - l + 1;
        ll t = p_2[len];
        cout << min(rmq[t][l], rmq[t][r - (1 << t) + 1]) << '\n';
    }

    return 0;
}
