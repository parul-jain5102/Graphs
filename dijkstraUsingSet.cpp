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
const int N=2e5+5;
set<pair<int,int>> s1; //pair of distance and source
int n,m;
VI dis(N,INT64_MAX);

void Dijkstra()
{
    VI par(n+1,-1);
    int src=1;
    dis[src]=0;
    s1.insert({dis[src],src});
    while(!s1.empty())
    {
        auto u=*s1.begin();
        s1.erase(s1.begin());
        int DisCurr=u.first;
        int CurrCity=u.second;
        for(auto x:adj[CurrCity])
        {
            int NewCity=x.first;
            int wt=x.second;
            if(dis[NewCity]>dis[CurrCity]+wt)
            {
                auto it=s1.find({dis[NewCity],NewCity});
                if(it!=s1.end())
                {
                    s1.erase(it);
                }
                dis[NewCity]=dis[CurrCity]+wt;
                par[NewCity]=CurrCity;
                s1.insert({dis[NewCity],NewCity});
            }

        }
    }
    // for(int i=2;i<=n;i++)
    // {
    //    cout<<"dis "<<i<<" = "<<dis[i]<<endl;
    // }
    for(int i=2;i<=n;i++)
    {
       int dest=i;
       while(dest!=src)
       {
           cout<<dest<<"<--";
           dest=par[dest];
       }
       cout<<src<<endl;
       cout<<"  Distance is: "<<dis[i]<<endl;
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
cin>>n>>m;
// int src,dest;
// cin>>src>>dest;
adj.resize(n+1);
dis.resize(n+1);
for(int i=0;i<m;i++)
{
    int u,v,wt;
    cin>>u>>v>>wt;
    adj[u].push_back({v,wt});
}
  Dijkstra();
   return 0;
}