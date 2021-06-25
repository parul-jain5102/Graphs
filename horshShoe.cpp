#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int main()
{
    fast
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int count=0;
    map<int,int> mp;
    for(int i=0;i<4;i++)
    {
        int x;
        cin>>x;
        mp[x]+=1;
        if(mp[x]>1)
        count++;
    }
    
    cout<<count;

    return 0;
}
