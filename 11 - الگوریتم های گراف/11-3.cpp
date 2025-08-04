// my solution
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll oo = 1e8+8;
const ll maxn = 1e3+5;

ll count_comp;
pair<ll,ll> loc[maxn];

bool mark[maxn];
void dfs(vector<ll> adj[],ll s){
	mark[s]=true;
	
	for(auto u:adj[s]){
		if(mark[u]==false){
			dfs(adj,u);
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	ll n;
	cin>>n;
	vector<ll> adj[n];
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		loc[i].first = x;
		loc[i].second = y;
		for(ll j=0;j<i;j++){
			ll x1 = loc[j].first ,y1 = loc[j].second;
			if(x==x1 or y==y1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
			
		}
	}
	count_comp = 0;
	for(ll i=0;i<n;i++){
		if(mark[i])
			continue;
		dfs(adj,i);
		count_comp++;
	}
	
	cout<<count_comp-1<<'\n';
		
	return 0;
}

// quera solution
// #include <bits/stdc++.h>

// using namespace std;

// const int MAXN = 1000 + 10;

// int x[MAXN], y[MAXN], n;
// bool mark[MAXN];

// // make a graph which vertexes correspond to each island
// // vertexes u, v are connected if and only if x[i] == x[j] || y[i] == y[j].
// // now we want to compute number of connected components in this graph.
// // and then we can add number of connected components minus one connections to make the graph connected.

// void DFS(int v)
// {
//     mark[v] = true;
//     for (int u = 0; u < n; u++)
//         if ((x[v] == x[u] || y[v] == y[u]) && !mark[u])
//             DFS(u);
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> x[i] >> y[i];

//     int ans = -1;
//     for (int i = 0; i < n; i++)
//     {
//         if (mark[i])
//             continue;
//         ans++;
//         DFS(i);
//     }
    
//     cout << ans << endl;
// }
