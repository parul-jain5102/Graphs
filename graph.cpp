#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
class Graph{
    public:
    int v;
    unordered_map<string,vector<pair<string,int>>> adj;
    Graph(int ver)
    {
        this->v=ver;
    }
    void AddEdge(string u,string v,int wt)
    {
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    void PrintGraph()
    {
        for(auto x:adj)
        {
            cout<<x.first<<" --> ";
            for(auto y:x.second)
            {
                cout<<" { "<<y.first<<" "<<y.second<<" } ";
            }
            cout<<endl;
        }
        // O(vertices+edges)
    }

};
int main()
{
    fast
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int v,e;
cin>>v>>e;

Graph G(v); //made graph object statically
//Graph *G1=new Graph(v); //made graph object dynamically
for(int i=0;i<e;i++)
{
    string a,b;
    cin>>a>>b;
    int c;
    cin>>c;
    G.AddEdge(a,b,c);
}
G.PrintGraph();



    return 0;
}