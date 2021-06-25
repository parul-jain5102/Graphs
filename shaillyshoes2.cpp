#include <bits/stdc++.h>
using namespace std;
int n,m,k,SizeOfComp;
vector<int> color;
vector<int> vis;
vector<vector<int>> adj;
vector<int> CompColors;
void DFS(int u)
{
   vis[u]=1;
   CompColors.push_back(color[u]);
   SizeOfComp++;
   for(auto x:adj[u])
   {
       if(!vis[x])
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
    cin>>n>>m>>k;
    adj.resize(n+1);
    vis.resize(n+1,0);
    color.resize(n+1);
    for(int i=1;i<=n;i++)
    {   
        cin>>color[i];
    }
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        adj[l].push_back(r);
        adj[r].push_back(l);
       
    }
    int ans=0;
     for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {   SizeOfComp=0;
            DFS(i);
            sort(CompColors.begin(),CompColors.end());
            int maxrep=1,rep=1;
            for(int i=0;i<CompColors.size()-1;i++)
            {
                if(CompColors[i]==CompColors[i+1])
                {  rep++;  }
                else
                {
                   rep=1;
                }
                maxrep=max(maxrep,rep);
                
            }
            ans+=(SizeOfComp-maxrep);
            CompColors.clear();
        }
    }
    cout<<ans;
   
    return 0;
}
