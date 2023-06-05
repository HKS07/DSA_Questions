class Solution {
    bool dfs( int node, int nodeCol, vector<int> &col, vector<vector<int>>& graph)
    {
        col[node] = nodeCol;
        
        for( auto adjNode: graph[node] )
        {
            if( col[adjNode] == -1 )
            {
                if( dfs( adjNode, !nodeCol, col, graph) == false ) return false;
            }
            else if( col[adjNode] == nodeCol )
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col( graph.size(), -1 );
        
        
        for( int i = 0; i < graph.size(); ++i )
        {
            if( col[i] == -1 )
                if( dfs( i, 0, col, graph ) == false) return false;
        }
        
        return true;
    }
};