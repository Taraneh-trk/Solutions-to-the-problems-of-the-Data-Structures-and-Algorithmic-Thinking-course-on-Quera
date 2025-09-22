// my solution
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pii;

bool comp(const pii& a, const pii& b){
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	ll n;
	cin>>n;
	pii a[n],b[n];
	for(ll i=0;i<n;i++){
		cin>>a[i].second;
		a[i].first=i;
	}
	for(ll i=0;i<n;i++){
		cin>>b[i].second;
		b[i].first=i;
	}
	
	ll ans=0;
	ll nb[n];
	sort(a,a+n,comp);
	sort(b,b+n,comp);
	
	for(ll i=0;i<n;i++){
		ans+=(a[i].second*b[i].second);
		nb[a[i].first] = b[i].second;
	}
	cout<<ans<<'\n';
	for(ll i=0;i<n;i++){
		cout<<nb[i]<<" ";
	}
	
	return 0;
}
// quera solution
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define S second
#define F first

int main()
{
    int n;
    cin >> n;

    vector<pair<pair<ll, ll>, int>> a(n);
    vector<ll> b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].F.F, a[i].S = i;
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i].F.F * b[i];
        a[i].F.S = b[i];
    }

    // Sort array based on order of input (index)
    sort(a.begin(), a.end(), [](auto &left, auto &right)
         { return left.second < right.second; });

    cout << ans << endl;
    for (int i = 0; i < n; i++)
        cout << a[i].F.S << ' ';
    cout << endl;
    return 0;
}
