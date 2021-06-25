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
const int N=2e5+5;
VI adj[N];
VI vis(N,-1);
int n,m;

void BFS()
{
    queue<pair<int,int>> q; //node and its color
    q.push({1,1});
    vis[1]=1;
    while(!q.empty())
    {
        auto u=q.front();
        q.pop();
        int CurrVertex=u.first;
        int CurrColor=u.second;
        for(auto x:adj[CurrVertex])
        {
            if(vis[x]==-1)
            {   vis[x]=3-CurrColor; //actually the color of x (if it was 1    earlier,   make it 3-1=2 and if it was 2 earlier ,make it 3-2=1 )
                q.push({x,vis[x]});
            }
            else if(vis[x]==CurrColor)
            {
                cout<<"Vertex "<<CurrVertex<<" and "<<x<<" have same color "<<CurrColor<<endl;
                return;
            }
        }


    }
    cout<<"The graph is Bi-Partite"<<endl;


}
void BiPartite()
{
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
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
BiPartite();

  
   return 0;
}