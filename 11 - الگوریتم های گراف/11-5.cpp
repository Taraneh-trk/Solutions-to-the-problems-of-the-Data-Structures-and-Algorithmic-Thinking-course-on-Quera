// solution with dfs
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1100;

// graph is a tree and we run DFS from node 1 and dis[v] equals to distance if node 1 and node v.
// is[v] is true if and only if there is a person in v.

bool is[MAXN];
vector<int> adj[MAXN];

int mn = 100000, dis[MAXN];

// par equals to parent of v that we called DFS(v) in par.
void DFS(int v, int par = -1)
{
    // find minimum distance of vertexes that a person is in them.
    if (is[v])
        mn = min(mn, dis[v]);

    for (auto u : adj[v])
        if (u != par)
        {
            // dis[u] is dis[v] plus 1
            dis[u] = dis[v] + 1;
            // v is parent of v and we called DFS(u) in v.
            DFS(u, v);
        }

    return;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int v;
        cin >> v;
        is[v] = true;
    }

    DFS(1);

    // print minimum index with minimum distance.
    for (int i = 1; i <= n; i++)
        if (is[i] && dis[i] == mn)
        {
            cout << i << "\n";
            return 0;
        }

    return 0;
}

// solution with bfs
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll oo = 1e8+8;
const ll maxn = 1e3+3;

ll dis[maxn];
void bfs(vector<ll> adj[],ll n){
	memset(dis,oo,sizeof(dis));
	queue<ll> q;
	dis[0] = 0;
	q.push(0);
	while(q.size()){
		auto v = q.front();
		q.pop();
		
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
	ll q;
	cin>>q;
	vector<ll> frnd(q);
	for(ll i=0;i<q;i++){
		ll f;
		cin>>f;
		f--;
		frnd[i] = f;
	}
	sort(frnd.begin(),frnd.end());
	bfs(adj,n);
	ll ans=0,min=oo;
	for(auto f:frnd){
		if(dis[f]<min){
			min=dis[f];
			ans=f+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
