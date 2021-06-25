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
bool IsSufficient(int t, int cooks, vector<int> ranks, int p)
{
    int parathas = 0;
    vector<int> alpha;
    for (int i = 1; i <= cooks; i++)
    {
        double temp = (sqrt((8 * t) / ranks[i] + 1) - 1) / 2;
        alpha[i] = floor(temp);
        parathas += alpha[i];
        if (parathas >= p)
            return true;
    }
    return false;
}
int ParathaTime(int l, int r, int cooks, vector<int> ranks, int p)
{
    int ans = 0;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (IsSufficient(mid, cooks, ranks, p))
        {
            ans = mid;
            r = mid - 1;
            IsSufficient(r, cooks, ranks, p);
        }
        else
        {
            l = mid + 1;
            IsSufficient(l, cooks, ranks, p);
        }
    }
    return ans;
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
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int p, l;
        cin >> p >> l;
        vector<int> rank(l, 0);
        for (int j = 1; j <= l; j++)
        {
            int x;
            cin >> x;
            rank.push_back(x);
        }
        int s = 0, e = 4 * p * (p + 1);
        cout << ParathaTime(s, e, l, rank, p) << endl;
    }

    return 0;
}