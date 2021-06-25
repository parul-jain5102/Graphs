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
VI adj[100];
vector<bool> vis;
int n,m;
int root=1;
bool IsCycle(int src)
{
    vis[src]=true;
    for(auto x:adj[src])
    {
        if(vis[x]==false)
        {
           return IsCycle(x);
        }
        else if(x==1)
        {
            return true;
        }
           
    }
    return false;
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
vis.resize(n+1,false);
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
if(IsCycle(1))
  cout<<"Cycle Found"<<endl;
else
   cout<<"Not Found"<<endl;

return 0;
}