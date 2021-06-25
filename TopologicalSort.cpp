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
VI adj[100];
vector<bool> vis(100);
int n,m;
vector<int> route;
bool IsCycle(int src)
{
    vis[src]=true;
    route[src]=1;
    cout<<"DFS "<<src<<"-->";
    for(int i=1;i<=n;i++)
    {
        if(route[i])
          cout<<i<<" ";
    }
    cout<<endl;
    
    for(auto x:adj[src])
    {
        if(vis[x]==false)
        {
            bool subProblem=IsCycle(x);
            if(subProblem==true)
               return true;
        }
        else if(vis[x]==true && route[x]==1)
        {
            return true;
        }
           
    }
    // cout<<"DFS "<<src<<"-->";
    // for(int i=1;i<=n;i++)
    // {
    //     if(route[i])
    //       cout<<i<<" ";
    // }
    // cout<<endl;
    route[src]=0;
    return false;

}
void BFS()
{
    // Kahn's algo for topological sort
    VI InDegree(n+1,0);
    for(auto x:adj)
    {
        for(auto y:x)
            InDegree[y]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(InDegree[i]==0)
           q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto x:adj[u])
        {
            InDegree[x]--;
            if(InDegree[x]==0)
                q.push(x);

        }
    }


}
void DFS(int src,stack<int> &s)
{
    vis[src]=true;
    for(auto x:adj[src])
    {
        if(!vis[x])
           DFS(x,s);
    }
    s.push(src);


}
void TopologicalSort()
{
    // stack<int> s;
    // for(int i=0;i<n;i++)
    // {
    //     if(!vis[i])
    //        DFS(i,s);
    // }
    // while(!s.empty())
    // {
    //    cout<<s.top()<<" ";
    //    s.pop();
    // }
    BFS();
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
cin>>n>>m;
// vis.resize(n+1,false);
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
}
TopologicalSort();
// route.resize(n+1,0);
// if(IsCycle(1))
//   cout<<"Cycle Found"<<endl;
// else
//    cout<<"Not Found"<<endl;
}