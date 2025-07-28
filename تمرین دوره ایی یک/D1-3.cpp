// quera solution
#include <iostream>
using namespace std;

const int maxn = 31; 
long long int f[maxn]; // Array to store the number of ways to reach each step

int main() {
    int n;
    cin >> n;

    f[0] = 1; // Base case: There's one way to be at the ground (0th step)

    // Calculate the number of ways to reach each step from 1 to n
    for (int i = 1; i <= n; i++) {
        f[i] += f[i - 1]; // One step from (i-1) to i
        if (i >= 2)
            f[i] += f[i - 2]; // Two steps from (i-2) to i
        if (i >= 5)
            f[i] += f[i - 5]; // Five steps from (i-5) to i
    }

    cout << f[n] << endl;
    return 0;
}
// my solution
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long int ll;

// ll dp[31];

// void solve(ll n){
// 	for(int i=6;i<=n;i++){
// 		dp[i] = dp[i-1] + dp[i-2] + dp[i-5];
// 	}
// }

// int main(){
// 	ios_base::sync_with_stdio(false);cin.tie(0);
	
// 	ll n;
// 	cin>>n;
	
// 	dp[0] = 0;
// 	dp[1] = 1;
// 	dp[2] = 2;
// 	dp[3] = 3;
// 	dp[4] = 5;
// 	dp[5] = 9;
	
// 	solve(n);
	
// 	cout<<dp[n]<<'\n';
	
// 	return 0;
// }
