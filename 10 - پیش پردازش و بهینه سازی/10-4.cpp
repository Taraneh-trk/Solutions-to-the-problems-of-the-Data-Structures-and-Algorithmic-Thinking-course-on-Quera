// my solution
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	ll n,m,k,initial_zero=0;
	cin>>n>>m>>k;
	ll M[n][m];
	ll ps[n+1][m+1];
	memset(ps,0,sizeof(ps));
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cin>>M[i][j];
			ps[i+1][j+1] = M[i][j] + ps[i][j+1] + ps[i+1][j] - ps[i][j];
			if(M[i][j]==0)
				initial_zero++;
		}
	}
	
	ll z1=0,z2=0,intersection=0,mox=0;
	for(int x11=0;x11<=n-k;x11++){
		for(int y11=0;y11<=m-k;y11++){
			z1=0,z2=0,intersection=0;
			int x21 = x11+k;
			int y21 = y11+k;
			z1 = ps[x21][y21] - ps[x11][y21] - ps[x21][y11] + ps[x11][y11];
			for(int x12=0;x12<=n-k;x12++){
				for(int y12=0;y12<=m-k;y12++){
					int x22 = x12+k;
					int y22 = y12+k;
					z2 = ps[x22][y22] - ps[x12][y22] - ps[x22][y12] + ps[x12][y12];
					int x1its = max(x11,x12), x2its = min(x21,x22);
					int y1its = max(y11,y12), y2its = min(y22,y21);
					intersection=0;
					if(x2its > x1its && y2its > y1its){
                        intersection = ps[x2its][y2its] - ps[x1its][y2its] - ps[x2its][y1its] + ps[x1its][y1its];
                    }
					if(z1+z2-intersection+initial_zero > mox)
						mox = z1+z2-intersection+initial_zero;
				}
			}
		}
	}
	cout<<mox<<'\n';
	
	return 0;
}

// quera solution
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 300;
// int a[MAXN][MAXN];
// int par[MAXN][MAXN];
// int dp[MAXN][MAXN];
// int k;

// int get(int i, int j)
// {
//     return par[i][j] + par[i - k][j - k] - par[i][j - k] - par[i - k][j];
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int n, m;
//     cin >> n >> m >> k;

//     int ans = n * m;
//     for (int solve = 0; solve < 2; solve++)
//     {
//         int total = 0;
//         if (!solve)
//         {
//             for (int i = 40; i < n + 40; i++)
//             {
//                 for (int j = 40; j < m + 40; j++)
//                 {
//                     cin >> a[i][j];
//                     total += a[i][j];
//                     par[i][j] = par[i - 1][j] + par[i][j - 1] - par[i - 1][j - 1] + a[i][j];
//                     dp[i][j] = max(get(i, j), max(dp[i - 1][j], dp[i][j - 1]));
//                 }
//             }
//         }

//         if (solve == 1)
//         {
//             for (int i = 40; i < n + 40; i++)
//                 reverse(a[i] + 40, a[i] + 40 + m);
//             for (int i = 40; i < n + 40; i++)
//             {
//                 for (int j = 40; j < 40 + m; j++)
//                 {
//                     total += a[i][j];
//                     par[i][j] = par[i - 1][j] + par[i][j - 1] - par[i - 1][j - 1] + a[i][j];
//                     dp[i][j] = max(get(i, j), max(dp[i - 1][j], dp[i][j - 1]));
//                 }
//             }
//         }

//         for (int i = 40; i < n + 40; i++)
//         {
//             for (int j = 40; j < m + 40; j++)
//             {
//                 for (int x = i - k + 1; x <= i; x++)
//                 {
//                     for (int y = j - k + 1; y <= j; y++)
//                     {
//                         int t = total - get(i, j) - get(x, y) + par[x][y] - par[i - k][y] - par[x][j - k] + par[i - k][j - k];
//                         ans = min(ans, t);

//                         ans = min(ans, total - get(i, j) - dp[i - k][j]);
//                         ans = min(ans, total - get(i, j) - dp[i][j - k]);
//                     }
//                 }
//             }
//         }
//     }

//     cout << n * m - ans << endl;
//     return 0;
// }
