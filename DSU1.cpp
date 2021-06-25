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
class Graph
{  int V;
   VPII edges;
   VI parent;
   VI ranks;
   public:
   Graph(int ver)
   {
       this->V=ver;
       parent.resize(V,-1);
       ranks.resize(V,1);
    }
    void AddEdge(int a,int b)
    {
        edges.push_back({a,b});
    }
    int Find(int a)
    {
        if(parent[a]==-1)
          return a;
        parent[a]=Find(parent[a]);
        return parent[a];

    }
    bool FindCycle()
    {
        for(auto edge:edges)
        {
            int a=edge.first;
            int b=edge.second;
            int s1=Find(a);
            int s2=Find(b);
            for (auto x:ranks)
                cout<<x<<" ";
            cout<<endl;
            
            if(s1!=s2)
            {
                if(ranks[s2]>ranks[s1])
                {
                    parent[s1]=s2;
                    ranks[s2]+=ranks[s1];
                }
                else
                {
                    parent[s2]=s1;
                    ranks[s1]+=ranks[s2];
                }
            }
            else
            {
                cout<<"Cycle Found "<<endl;
                cout<<s1<<" "<<s2<<endl;
                return true;
            }
        }
        cout<<" No Cycle Found"<<endl;
        return false;


    }

};



int32_t main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
Graph *g=new Graph(4);
g->AddEdge(0,1);
g->AddEdge(1,2);
g->AddEdge(2,3);
g->AddEdge(3,0);
cout<<g->FindCycle();

return 0;
}