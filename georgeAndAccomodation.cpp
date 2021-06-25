#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<bits/stdc++.h>
using namespace std;
int main()
{
    fast 
    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif
    int n,count=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int p,q;
        cin>>p>>q;
        int diff=q-p;
        if(diff>=2)
        {
            count++;
        }
        

    }
    cout<<count;
    return 0;
    
 }