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
int n,m;
class MyComp
{
    public:
        bool operator()(const PII &a,const PII &b)
        {
            return b.first<a.first;
        }

};
void Dijkstra()
{
    VI dis(n+1,INT64_MAX);
    VI par(n+1,-1);
    priority_queue<PII,VPII,MyComp> pq;
    int src=1;
    dis[src]=0;
    pq.push({dis[src],src});
    while(!pq.empty())
    {
        auto u=pq.top();
        cout<<u.first<<" "<<u.second<<endl;
        pq.pop();
        int CurrDis=u.first;
        int CurrVer=u.second;
        for(auto x:adj[CurrVer])
        {
            int neighbourCity=x.first;
            int wt=x.second;
            if(dis[neighbourCity]>dis[CurrVer]+wt)
            {
                dis[neighbourCity]=dis[CurrVer]+wt;
                par[neighbourCity]=CurrVer;
                pq.push({dis[neighbourCity],neighbourCity});

            }

        }

    }
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
adj.resize(n+1);
for(int i=0;i<m;i++)
{
    int u,v,wt;
    cin>>u>>v>>wt;
    adj[u].push_back({v,wt});
}
  Dijkstra();
   return 0;
}