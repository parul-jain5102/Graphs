class Solution
{
    public:
    int r,c;
    int IlandSize=0;
    int ans=0;
    vector<vector<int>> vis;

bool IsSafe(int x, int y,vector<vector<int>>& grid)
{
    if (x >= 0 && x < r && y >= 0 && y < c && !vis[x][y] && grid[x][y]==1)
        return true;
    return false;
}

void DFS(int x, int y,vector<vector<int>>&  grid)
{
    int dx[8] = {-1, 0, 1, 0,1,1,-1,-1};
    int dy[8] = {0, 1, 0, -1,1,-1,1,-1};
    vis[x][y]=1;
    IlandSize++;
    for (int i = 0; i <8; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (IsSafe(newx, newy,grid))
        {
            DFS(newx, newy,grid);
        }
    }
}
    int findMaxArea(vector<vector<int>>& grid) {
        c=grid[0].size();
        r=grid.size();
        vis.resize(r + 1, vector<int>(c + 1, 0));
        int NoOfIland=0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                IlandSize = 0;
                DFS(i, j,grid);
                NoOfIland++;
                ans = max(ans, IlandSize);
            }
        }
    }
    return ans;
    }
};
