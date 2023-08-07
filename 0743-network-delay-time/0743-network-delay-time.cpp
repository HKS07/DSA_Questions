class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
         vector<pair<int,int>> adj[n];
        for( auto e: edges )
        {
            int u = e[0]-1, v = e[1]-1, wt = e[2];

            adj[u].push_back({v,wt});
            // adj[v].push_back({u,wt});
        }

        vector<int> dist(n,1e9);
        dist[k-1] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k-1});

        while( !pq.empty() )
        {
            int dis = pq.top().first, node = pq.top().second;
            pq.pop();
            for( auto it: adj[node])
            {
                int adjNode = it.first, wt = it.second;
                if( dis + wt < dist[adjNode] )
                {
                    dist[adjNode] = dis + wt;
                    pq.push({dis + wt,adjNode});
                }
            }
        }
        int mx = 0;
        for( auto d: dist )
        {
            if( d == 1e9 ) return -1;
            mx = max(d,mx);
        }
        return mx;
    }
};