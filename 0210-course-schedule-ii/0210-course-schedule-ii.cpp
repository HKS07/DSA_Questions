class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> inDegree(n,0);
        vector<int> adj[n];
        for( int i = 0; i < p.size(); ++i )
        {
            inDegree[p[i][0]]++;
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int> topo;
        queue<int> q;
        int cnt = 0;
        for( int i = 0; i < n; ++i )
        {
            if( inDegree[i] == 0 )
                q.push(i);
        }
        
        while( !q.empty() )
        {
            int node = q.front(); q.pop();
            topo.push_back(node);
            cnt++;
            for( auto ngbr: adj[node] )
            {
                inDegree[ngbr]--;
                if( inDegree[ngbr] == 0 ) q.push(ngbr);
            }
        }
        if( cnt != n ) return {};
        return topo;
    }
};