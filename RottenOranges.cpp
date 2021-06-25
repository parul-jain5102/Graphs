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
#define fi first 
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSET;
map<pair<int,int>,pair<int,int>> adj;
queue<cell> q;
struct cell
{
    int x,y;
    int time;
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
int r,c;
cin>>r>>c;
map<pair<int,int>,pair<int,int>> mp;
for(int i=1;i<=r;i++)
{
    for(int j=1;j<=c;j++)
    {
       int x;
       cin>>x;
       mp[{i,j}].first=x;
       if(x==-1)
          mp[{i,j}].second=0;
       else
           mp[{i,j}].second=INT64_MAX;

    }
}
for(int i=1;i<=r;i++)
{
    for(int j=1;j<=c;j++)
    {
       if(mp[{i,j}].first==-1) //that is that orange is rotten
       {
           q.push({i,j});
           if(mp[{i+1,j}].first==-1)
           {
               q.push({i+1,j});
           }
           if(mp[{i-1,j}].first==-1)
           {
               q.push({i-1,j});
           }
           if(mp[{i,j+1}].first==-1)
           {
               q.push({i,j+1});
           }
           if(mp[{i,j-1}].first==-1)
           {
               q.push({i,j-1});
           }


          
       }

    }
}




  
   return 0;
}
