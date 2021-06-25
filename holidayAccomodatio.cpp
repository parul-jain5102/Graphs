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
vector<vector<pair<int,int>>> adj;
int ans,n;
int DFS(int src,int par,int edgeWt)
{
    int count=0;
    for(auto x:adj[src])
    {
        if(x.first==par)
           continue;
        else
        {
            count+=DFS(x.first,src,x.second);
        }
    }
    count++;
    if(par!=-1)
      ans+=(2*min(count,(n-count))*edgeWt);
return count;
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
int t;
cin>>t;
for(int i=1;i<=t;i++)
{
    cin>>n;
    adj.resize(n+1);
    for(int j=1;j<=n-1;j++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});


    }
    ans=0;
    DFS(1,-1,0);
    adj.clear();
    cout<<"Case #"<<i<<": "<<ans<<endl;
}

  
   return 0;
}
