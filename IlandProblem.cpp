// #define fast                          \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make pair
#define PB push back
#define MOD 1000000007
#define fi first #define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSET;
VVI mat, vis, adj;
int r, c;
int IlandSize;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool IsSafe(int x, int y)
{
    // if (x >= 1 && x <= r && y >= 1 && y <= c && !vis[x][y] && mat[x][y]==1)
    if (x >= 1 && x <= r && y >= 1 && y <= c && mat[x][y] == 1)
        return true;
    return false;
}
void BFS(int x, int y)
{
    mat[x][y] = -1;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        IlandSize++;
        auto u = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++)
        {
            int newx = u.first + dx[i];
            int newy = u.second + dy[i];
            if (IsSafe(newx, newy))
            {
                mat[newx][newy]=-1;
                q.push({newx,newy});

            }
        }
    }
}
void DFS(int x, int y)
{
    // vis[x][y] = 1;
    mat[x][y] = -1;
    IlandSize++;
    for (int i = 0; i <= 3; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (IsSafe(newx, newy))
        {
            DFS(newx, newy);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> r >> c;
    mat.resize(r + 1, VI(c + 1));
    vis.resize(r + 1, VI(c + 1, 0));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> mat[i][j];
        }
    }

    int NoOfIland = 0, ans = -1;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            // if (!vis[i][j] && mat[i][j] == 1)
            if (mat[i][j] == 1)
            {
                IlandSize = 0;
                // DFS(i, j);
                BFS(i, j);
                NoOfIland++;
                ans = max(ans, IlandSize);
            }
        }
    }
    cout << NoOfIland << " " << ans;
    // visited matrix was actually not needed

    return 0;
}