//quera solution
#include <bits/stdc++.h>

using namespace std;

const int maxn = 250; // Maximum dimension for the arrays
char A[maxn][maxn], a[maxn][maxn], tmp[maxn][maxn];
int n, dim;

// Function to generate the fractal pattern
void make(int step) {
    if (step == 1) { // base
        dim = n; // Set the initial dimension
        // Copy the initial pattern into a
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = A[i][j];
        return;
    }
    make(step - 1); // Recursively create the pattern for step-1

    // Create the new pattern based on the previous pattern
    for (int i = 0; i < dim * n; i++)
        for (int j = 0; j < dim * n; j++)
            tmp[i][j] = (a[i / n][j / n] == '*' ? '*' : A[i % n][j % n]);

    dim *= n; // Update the dimension
    // Copy the new pattern back into a
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            a[i][j] = tmp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    // Generate the fractal pattern
    make(k);

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++)
            cout << a[i][j];
        cout << '\n';
    }
    return 0;
}


//my solution
//#include <bits/stdc++.h>
//using namespace std;
//
//
//typedef long long int ll;
//
//string grid_ans[3*3*3*3*3 + 1][3*3*3*3*3 + 1];
//string grid_org[3*3*3*3*3 + 1][3*3*3*3*3 + 1];
//string grid[3*3*3*3*3 + 1][3*3*3*3*3 + 1];
//
//void solve(ll n,ll k,ll s,ll x){
//	if(x==k){
//		for(int i=0;i<s;i++){
//			for(int j=0;j<s;j++){
//				cout<<grid_ans[i][j];
//			}
//			cout<<'\n';
//		}
//		return ;
//	}
//	
//	ll ns = s*n;
//	ll r=0,c=0,rs[s],cs[s];
//	memset(rs,0,sizeof(rs));
//	memset(cs,0,sizeof(cs));
//	for(int i=0;i<s;i++){
//		for(int j=0;j<s;j++){
//			
//			if(grid[i][j]=="."){
//				
//				r = cs[j]*n;
//				c = rs[i]*n;
//				
//				for(int di=r,orgi=0;di<r+n;orgi++,di++){
//					for(int dj=c,orgj=0;dj<c+n;orgj++,dj++){
//						grid_ans[di][dj] = grid_org[orgi][orgj];
//					}
//				}
//				
//				rs[i]++;
//				cs[j]++;
//				
//			}else if(grid[i][j]=="*"){
//				r = cs[j]*n;
//				c = rs[i]*n;
//				
//				for(int di=r;di<r+n;di++){
//					for(int dj=c;dj<c+n;dj++){
//						grid_ans[di][dj] = "*";
//					}
//				}
//				
//				rs[i]++;
//				cs[j]++;
//			}
//			
//		}
//	}
//	
//	for(int i=0;i<ns;i++){
//		for(int j=0;j<ns;j++){
//			grid[i][j] = grid_ans[i][j];
//		}
//	}
//	
//	solve(n,k,ns,x+1);
//}
//
//int main(){
//	ios_base::sync_with_stdio(false);cin.tie(0);
//	
//	ll n,k;
//	cin>>n>>k;
//	cin.ignore();
//	string s;
//	for(int i=0;i<n;i++){
//		getline(cin,s);
//		for(int j=0;j<n;j++){
//			grid_org[i][j] = s[j];
//			grid[i][j] = s[j];
//			grid_ans[i][j] = s[j];
//		}
//	}
//	
//	solve(n,k,n,1);
//	
//	return 0;
//}
