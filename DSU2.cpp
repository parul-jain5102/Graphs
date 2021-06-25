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
VI parent;
VI ranks;
int n,m;
int Find(int a)
{
    if(parent[a]==-1)
          return a;
    parent[a]=Find(parent[a]);
    return parent[a];
}
void union_set(int a,int b)
{
   int s1=Find(a);
   int s2=Find(b); 
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
int n,m;
cin>>n>>m;
parent.resize(n,-1);
ranks.resize(n,1);
for(int i=0;i<m;i++)
{
    int NuOfPeople;
    cin>>NuOfPeople;
    VI friends(NuOfPeople);
    for(int i=0;i<NuOfPeople;i++)
    {
        int a;
        cin>>a;
        a--;
        friends[i]=a;

    }
    for (int i=0;i<NuOfPeople-1;i++)
    {
        int a=friends[i];
        int b=friends[i+1];
        union_set(a,b);
    }
    
}
for(int i=0;i<n;i++)
{
    cout<<ranks[Find(i)]<<" ";      
}

return 0;
}