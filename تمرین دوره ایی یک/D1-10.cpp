#include <bits/stdc++.h>

#define F first
#define S second
#define pii pair<int, int>
#define pb push_back

typedef long long ll;

using namespace std;

const int maxN = 5e4 + 10;

int a[maxN];

bool have[(int)(5e6)];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	if(n > 20) return cout << "YAY!\n", 0;

	for (int mask=0; mask<(1 << n); mask++) {
		ll sum = 0;
		for (int i=0; i<n; i++)
			if(mask & (1 << i)) sum += a[i];
		if(have[sum]) return cout << "YAY!\n", 0;
		have[sum] = true;

	}	
	return cout << "AWW!\n", 0;
}
