// my solution
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin>>n;
	ll c[n+1];
	c[0]=0;
	for(ll i=0;i<n;i++){
		cin>>c[i+1];
	}
	
	pair<ll,ll> mins[n+1];
	mins[n].first = c[n];
	mins[n].second = n;
	for(ll i=n-1;i>=0;i--){
		if(c[i+1]<mins[i+1].first){
			mins[i].first = c[i+1];
			mins[i].second = i+1;
		}else{
			mins[i].first = mins[i+1].first;
			mins[i].second = mins[i+1].second;
		}
	}
	
	ll ans=0;
	ll i=0;
	while(i!=n){
		ll to = mins[i].second;
		ans+=(c[to]*abs(i-to)); 
		i = to;
	}
	cout<<ans<<'\n';
	
	return 0;
}
// quera solution
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e6; 
int c[maxn]; // Array to store the cost of repairing each backdoor

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];

    int mini = c[n - 1];
    long long int ans = c[n - 1]; 

    // Calculate the minimum cost to repair the backdoors from right to left
    for (int i = n - 2; i >= 0; i--) {
        mini = min(mini, c[i]); // Update mini to the smallest cost encountered
        ans += mini; // Add the minimum cost to the total cost
    }

    cout << ans << endl;
    return 0;
}

