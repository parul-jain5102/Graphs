 class mycomp
{
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return b.second < a.second;
    }
};
int Prims(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int> , vector<pair<int,int>> , mycomp> pq;
        vector<int> vis(V + 1, 0);
        vis[2] = 1;
        for (auto x : adj[2])
        {
            int vertex = x[0];
            int wt = x[1];
            pq.push({vertex, wt});
        }
        int ans = 0;
        while (!pq.empty())
        {
            auto u = pq.top();
            pq.pop();
            int currVert = u.first;
            int wt = u.second;
            if (!vis[currVert])
            {
                vis[currVert] = 1;
                // cout << currVert << "--->";
                ans += wt;
                for (auto y : adj[currVert])
                {
                    int vertex = y[0];
                    int wt = y[1];
                    pq.push({vertex, wt});
                }
            }
        }
        // cout << endl;
        return ans;
    }

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
       
        
        return Prims(V,adj);
    }
};
