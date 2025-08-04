// my solution
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

const ll oo = 1e8+8;
const ll maxn = 2*3*4*5*6*7*8+5;

ll fact[maxn];
void factorial_(ll n){
	fact[0]=1;
	for(ll i=1;i<=n;i++){
		fact[i] = fact[i-1]*i;
	}
}

ll getid(const vector<ll> &a, ll n) {
    ll id = 0;
    vector<bool> used(n+1, false);
    for(ll i=0; i<n; i++) {
        ll smaller = 0;
        for(int j=1; j<a[i]; j++) {
            if(!used[j]) smaller++;
        }
        id += smaller * fact[n - i - 1];
        used[a[i]] = true;
    }
    return id;
}

void bfs(vector<ll> s,ll n,vector<ll> target){
	ll dis[fact[n]];
	memset(dis,oo,sizeof(dis));
	ll ids = getid(s,n);
	dis[ids]=0;
	
	queue<vector<ll>> q;
	q.push(s);
	while(q.size()){
		auto v = q.front();
		q.pop();
		ll idv = getid(v,n);
		for(ll i=1;i<n;i++){
			reverse(v.begin(),v.begin()+i+1);
			ll idu = getid(v,n);
			if(dis[idu]>dis[idv]+1){
				dis[idu] = dis[idv]+1;
				q.push(v);
			}
			reverse(v.begin(),v.begin()+i+1);
		}
	}
	
	ll ide = getid(target,n);
	cout<<dis[ide]<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	ll n;
	cin>>n;
	vector<ll> a(n),target(n);
	factorial_(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
		target[i]=i+1;
	}
	
	bfs(a,n,target);
		
	return 0;
}

// quera solution
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 1e6 + 10, MAXE = 10, INF = 1e9;

// int dis[MAXN], a[MAXE], fact[MAXE], n;

// queue<vector<int>> q;
// vector<int> v;

// // this function return number of permutation 'r' in base factorial
// // equals to r[0] * n! + r[1] * (n - 1)! + ... + r[n - 1] * 1!
// int getId(vector<int> r)
// {
//     int res = 0;
//     for (int i = 0; i < n; i++)
//         res += r[i] * fact[n - i];
//     return res;
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     // computing factorials : fact[i] = i!
//     fact[0] = 1;
//     for (int i = 1; i <= n; i++)
//         fact[i] = fact[i - 1] * i;

//     for (int i = 0; i < n; i++)
//         v.push_back(a[i]);

//     for (int i = 0; i < MAXN; i++)
//         dis[i] = INF;

//     // dis[i] is number of operations needed to convert initial permutation to a permutation that it's id(number in base factorial) is i.

//     // q is the queue of permutations
//     q.push(v);

//     // starting node
//     dis[getId(v)] = 0;

//     while (!q.empty())
//     {
//         vector<int> perm = q.front();
//         q.pop();
//         int c = getId(perm);
//         // c = number of perm in base factorial

//         for (int i = 2; i <= n; i++)
//         {
//             vector<int> r;
//             for (int j = i - 1; j >= 0; j--)
//                 r.push_back(perm[j]);
//             for (int j = i; j < n; j++)
//                 r.push_back(perm[j]);
//             // r is permutation by inverting first i element if perm.

//             int id = getId(r);
//             if (dis[id] > dis[c] + 1)
//             {
//                 dis[id] = dis[c] + 1;
//                 q.push(r);
//             }
//         }
//     }

//     v.clear();
//     for (int i = 1; i <= n; i++)
//         v.push_back(i);
//     // v is sorted permutation.

//     int id = getId(v);
//     cout << dis[id] << '\n';

//     return 0;
// }
