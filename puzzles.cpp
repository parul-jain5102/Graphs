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
    int n, m;
    vector<int> v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int j = n - 1;
    int md = 1000;
    for (int i = 0; i <= v.size() - n; i++)
    {
        if (j < m)
        {
            int a = v[j] - v[i];
            md = min(md, a);
            j++;
        }
    }
    cout << md;
    return 0;
}
