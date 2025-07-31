#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	ll n,q;
	cin>>n>>q;
	set<ll> sets[n];
	for(int i=0;i<n;i++){
		sets[i].insert(i+1);
	}
	for(ll i=1;i<=q;i++){
		ll t;
		cin>>t;
		switch(t){
			case 1:
				ll from,to;
				cin>>from>>to;
				sets[to-1].insert(sets[from-1].begin(),sets[from-1].end());
				sets[from-1].clear();
				break;
			case 2:
				ll size;
				cin>>size;
				cout<<sets[size-1].size()<<'\n';
				break;
			case 3:
				ll show;
				cin>>show;
				if(sets[show-1].empty()){
					cout<<-1;
				}else{
					for(auto item:sets[show-1]){
						cout<<item<<" ";
					}
				}
				cout<<'\n';
				break;
		}
	}
	
	return 0;
}
