// my solution
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin>>n;
	multiset<ll> w;
	ll w_[n];
	for(ll i=0;i<n;i++){
		cin>>w_[i];
	}
	sort(w_,w_+n);
	for(int i=0;i<n;i++){
		w.insert(w_[i]);
	}
	ll size=w.size();
	ll ans=0;
	while(size!=1){
		auto a=w.begin();w.erase(a);
		auto b=w.begin();w.erase(b);
		ll temp=*a+*b;
		ans+=temp;
		w.insert(temp);
		size=w.size();
	}
	cout<<ans<<'\n';
	
	return 0;
}
// quera solution
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;

    ll w[n];
    for (int i = 0; i < n; i++)
        cin >> w[i];

    ll ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        sort(w + i, w + n);
        ans += w[i] + w[i + 1];
        w[i + 1] = w[i] + w[i + 1];
    }

    cout << ans << endl;
    return 0;
}
