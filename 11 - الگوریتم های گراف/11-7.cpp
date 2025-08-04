// solution with bfs
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll oo = 1e8+8;
const ll maxn = 1e5+5;

ll dis[maxn];
bool mark[maxn];
void bfs(vector<ll> adj[],ll n,ll s){
	memset(dis,oo,sizeof(dis));
	queue<ll> q;
	dis[s]=0;
	q.push(s);
	
	while(q.size()){
		auto v = q.front();
		q.pop();
		mark[v]=true;
		for(auto u:adj[v]){
			if(dis[u]>dis[v]+1){
				dis[u] = dis[v]+1;
				q.push(u);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	ll n;
	cin>>n;
	vector<ll> adj[n];
	for(ll i=0;i<n-1;i++){
		ll f,t;
		cin>>f>>t;
		f--;t--;
		adj[f].push_back(t);
		adj[t].push_back(f);
	}
	ll ans = 0;
	bfs(adj,n,0);
	ll mox = 0,index=0;
	for(ll i=0;i<n;i++){
		if(dis[i]<50000+5 and dis[i]>mox){
			mox = dis[i];
			index = i;
		}
	}
	bfs(adj,n,index);
	for(ll i=0;i<n;i++){
		if(dis[i]<50000+5 and dis[i]>ans){
			ans = dis[i];
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}

// solution with dfs
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 50 * 1000 + 10;

// vector<int> adj[MAXN];
// int h[MAXN];

// void DFS(int v, int par = -1)
// {
//     for (auto u : adj[v])
//     {
//         if (u == par)
//             continue;
//         h[u] = h[v] + 1; // finding heights
//         DFS(u, v);
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n - 1; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         u--;
//         v--;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     DFS(0);

//     int maxH = -1;
//     for (int i = 0; i < n; i++)
//         if (maxH == -1 || h[i] > h[maxH])
//             maxH = i;

//     memset(h, 0, sizeof h); // initiallizing
//     DFS(maxH);

//     int ans = 0;
//     for (int i = 0; i < n; i++)
//         ans = max(ans, h[i]);
//     cout << ans << "\n";
   
//     return 0;
// }
