class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n], vis(n,0);
        
        for( int i = 0; i < n; ++i )
        {
            for(int j = 0; j < n; ++j )
            {
                if( isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int province = 0;
        
        
        
        for( int i = 0; i < n; ++i )
        {
            if( !vis[i] )
            {
                province++;
                queue<int> q; q.push(i);
                vis[i] = 1;
                while( !q.empty())
                {
                    int node = q.front(); q.pop();
                    
                    for( auto adjNode : adj[node] )
                    {
                        if( !vis[adjNode] )
                        {
                            q.push(adjNode);
                            vis[adjNode] = 1;
                        }
                    }
                }
            }
        }
        return province;
    }
    
};