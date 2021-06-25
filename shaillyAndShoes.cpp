#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m,k,cnt=0;
    cin>>n>>m>>k;
    vector<int> c;
    // int c[2000000];
    for(int i=1;i<=n;i++)
    {   
        // cin>>c[i]; 
        int a;
        cin>>a;
        c.push_back(a); 
    }
    // for(auto l:c)
    // {
    //     cout<<l<<" ";
    // }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<c[i]<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(c[x-1]==c[y-1])
        {
            continue;
        }
        else
        {
            c[x-1]=c[y-1];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
