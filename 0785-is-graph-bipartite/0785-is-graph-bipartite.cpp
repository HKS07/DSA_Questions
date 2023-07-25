class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        
        for(int i = 0; i < n; ++i )
        {
            if( col[i] == -1 )
            {
                queue<pair<int,int>> q; q.push({i,0});
                col[i] = 0;
                while( !q.empty() )
                {
                    int node = q.front().first, color = q.front().second;
                    q.pop();
                    for( auto ngbr: graph[node] )
                    {
                        if( col[ngbr] == -1 )
                        {
                            col[ngbr] = !color;
                            q.push({ngbr, !color});
                        }
                        else if( col[ngbr] == color ) return false;
                    }
                }
            }
        }
        return true;
    }
};