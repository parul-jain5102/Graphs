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
int len;
string str;
cin>>len;
cin>>str;
for(int i=0;i<len;i++)
{
    char x=str[i];
    if (isupper(x)) 
       str[i]=str[i]+32;
}
// cout<<str;

map<int,int> mp;
for(int i=0;i<len;i++)
{   int a=str[i];
   mp[a]++;
}
int cnt=0;
    for (auto i : mp)
    {
        if(i.second!=0)
        {
            cnt++;
        }
    }
    // for (auto i : mp)
    //     cout << i.first << "   " << i.second<< endl;
        // cout <<cnt;
if(cnt==26)
{
    cout<<"YES";
}  
else
cout<<"NO";      

return 0;
 
}