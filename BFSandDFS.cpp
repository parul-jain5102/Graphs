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
int n, e;

unordered_map<char, vector<char>> adj;
void BFS(char src, char desti)
{
   unordered_map<char, int> dis;
   for (auto x : adj)
   {
      char cityName = x.first;
      dis[cityName] = INT64_MAX;
   }
   unordered_map<char, char> parent;
   queue<char> q;
   q.push(src);
   dis[src] = 0;
   while (!q.empty())
   {
      auto u = q.front();
      cout << u << " ";
      q.pop();
      for (auto x : adj[u])
      {
         if (dis[x] == INT64_MAX)
         {
            q.push(x);
            dis[x] = dis[u] + 1,
            parent[x] = u;
         }
      }
   }
   cout<<endl;
   cout << "Shortest distance from " << src << " to " << desti << " is: " << dis[desti] << endl;
   while (desti != src)
   {
      cout << desti << "<--";
      desti = parent[desti];
   }
   cout << src << endl;
}

unordered_map<char, bool> vis;
void DFS(char src)
{
   cout << "DFS " << src << endl;
   vis[src] = true;
   for (auto x : adj[src])
   {
      if (!vis[x])
      {
         DFS(x);
      }
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
   cin >> n >> e;
   for (int i = 0; i < e; i++)
   {
      char c1, c2;
      cin >> c1 >> c2;
      adj[c1].push_back(c2);
      adj[c2].push_back(c1);
   }
   char source = 'b', dest = 'a';
   // BFS(source, dest);
   for(auto x:adj)  //printing adj list
   {
      cout<<x.first<<"-->";
      for(auto y:x.second)
      {
         cout<<y<<" ";
      }
      cout<<endl;
      vis[x.first]=false; //initialise every node to be unvisited
   }
   DFS(source);
   return 0;
}
