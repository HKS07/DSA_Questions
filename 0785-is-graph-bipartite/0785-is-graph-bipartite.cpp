class Solution {
public:
    bool check( int start, vector<vector<int>>& graph, vector<int> &color)
    {
        // vector<int> color(graph.size(),-1); color[0] = 0;
        queue<int> q; q.push(start);
        color[start] = 0;
        
        while( !q.empty() )
        {
            int node = q.front(); q.pop();
            
            for( auto adjNode: graph[node] )
            {
                if( color[adjNode] == -1 )
                {
                    // Node is not colored
                    // color[adjNode] = color[0] == 0? 1:0;
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                }
                else if( color[adjNode] == color[node] )
                {
                    return false;
                }
                // else
                // {
                //  // Node is colored
                //     if( color[node] != color[adjNode] )
                //     {
                //         // same color
                //         q.push(adjNode);
                //     }
                //     else
                //     {
                //         // different color
                //         return false;
                //     }
                // }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1); 
        for( int i  = 0; i < graph.size(); ++i )
        {
            if( color[i] == -1 )
            {
                if( check( i, graph, color) == false ) return false;
            }
        }
        return true;
    }
};