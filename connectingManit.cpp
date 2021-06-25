#include <bits/stdc++.h>
using namespace std;

vector<int> cycleSize;
vector<int> vis;
vector<vector<int>> adj;
int LenOfCycle;
void DFS(int u)
{   if(vis[u]==1)
        return;
    vis[u]=1;
    LenOfCycle++;
    for(auto x:adj[u])
    {
           DFS(x);
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
int n;
cin>>n;
adj.resize(n+1);
vis.resize(n+1,0);
for(int i=1;i<=n;i++)
{
  int a;
  cin>>a;
  adj[i].push_back(a);
}
for(int i=1;i<=n;i++)
{
    if(!vis[i])
    {
        LenOfCycle=0;
        DFS(i);
        cycleSize.push_back(LenOfCycle);
    }
}
int sum=0;
sort(cycleSize.begin(),cycleSize.end(),greater<int>());
for(auto x:cycleSize)
{
    sum+=(x*x);
}
if(cycleSize.size()>=2)
{
    sum+=(2*cycleSize[0]*cycleSize[1]);
}
cout<<sum;
    
    return 0;
}
