class Solution {
public:
    
int timer = 1;
void dfs(int node, int parent, int tin[], int low[], vector<int> &vis, vector<int> adj[], vector<vector<int>>& b)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for( auto adjNode: adj[node] )
    {
        if( adjNode == parent ) continue;
        if( !vis[adjNode] )
        {
            dfs(adjNode, node, tin, low, vis, adj, b);
            low[node] = min(low[node], low[adjNode]);

            if( low[adjNode] > tin[node] )
            {
                b.push_back({adjNode,node});
            }
        }
        else
        {
            low[node] = min(low[node], low[adjNode]);
        }
    }
}
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& c) {
        vector<int> adj[v];
        for( auto e: c )
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int tin[v], low[v];
        vector<int> vis(v,0);
        vector<vector<int>> b;
        
        dfs(0, -1, tin, low, vis, adj, b);

        return b;
    }
};