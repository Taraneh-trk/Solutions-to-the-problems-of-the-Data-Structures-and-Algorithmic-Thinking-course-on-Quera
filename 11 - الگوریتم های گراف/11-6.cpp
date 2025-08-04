// my solution
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn = 1005;

ll n;
ll grid[maxn][maxn];
bool mark[maxn][maxn];

vector<pair<int,int>> comp; 

int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};

void dfs(int r,int c, int h){
    mark[r][c] = true;
    comp.push_back({r,c});
    for(int i=0; i<8; i++){
        int nr = r + dr[i], nc = c + dc[i];
        if(nr >= 0 && nr < n && nc >=0 && nc < n){
            if(!mark[nr][nc] && grid[nr][nc] == h){
                dfs(nr,nc,h);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    ll peaks = 0, valleys = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!mark[i][j]){
                comp.clear();
                dfs(i,j,grid[i][j]);
                int h = grid[i][j];
                bool is_peak = true, is_valley = true;
                for(auto &cell : comp){
                    int r = cell.first, c = cell.second;
                    for(int d=0; d<8; d++){
                        int nr = r + dr[d], nc = c + dc[d];
                        if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
                        if(mark[nr][nc] && grid[nr][nc]==h) continue; 

                        if(grid[nr][nc] > h) is_peak = false;
                        if(grid[nr][nc] < h) is_valley = false;

                        if(!is_peak && !is_valley) break;
                    }
                    if(!is_peak && !is_valley) break;
                }
                if(is_peak) peaks++;
                if(is_valley) valleys++;
            }
        }
    }

    cout << peaks << " " << valleys << "\n";

    return 0;
}
// quera solution
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int a[MAXN][MAXN], n, cnt, id[MAXN][MAXN];
// id[i][j] is number of component of (i, j)
// cnt is number of connected components.
// a component is block as described in task.

bool f1[MAXN * MAXN], f2[MAXN * MAXN];
// f2[i] is false if and only if component i is "darre".
// f1[i] is false if and only if component i is "gholle"

const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1}, dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

// find connected components
void DFS(int x, int y)
{
    id[x][y] = cnt;
    // this for will iterate over neighbors of (x, y)
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (a[nx][ny] == a[x][y] && id[nx][ny] == -1)
            DFS(nx, ny);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    memset(id, -1, sizeof id); // will fill all id[i][j] with -1

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (id[i][j] != -1)
                continue;
            DFS(i, j);
            cnt++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c = id[i][j];
            // this for will iterate over neighbors of (i, j)
            for (int k = 0; k < 8; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                //(nx, ny) is neighbor of (i, j).
                if (id[nx][ny] != id[i][j])
                {
                    if (a[nx][ny] < a[i][j])
                        f1[id[i][j]] = true; // component of (i, j) cannot be "darre"
                    else
                        f2[id[i][j]] = true; // component of (i, j) cannot be "gholle"
                }
            }
        }
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (!f2[i])
            ans1++; // add number of "gholle"
        if (!f1[i])
            ans2++; // add number of "darre"
    }

    cout << ans1 << ' ' << ans2 << endl;
    
    return 0;
}
