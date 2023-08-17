class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n,vector<int> (n,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;// dist,{i,j}
        pq.push({grid[0][0],{0,0}});
        dis[0][0] = grid[0][0];
        
        int delR[4] = {0,-1,0,1};
        int delC[4] = {-1,0,1,0};
        while( !pq.empty() )
        {
            int maxForParNode = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            
            
            for(int del= 0; del < 4; ++del )
            {
                int r = i + delR[del], c = j + delC[del];
                
                if( r >= 0 && r < n && c >= 0 && c < n )
                {
                    int maxForCurNode = max( maxForParNode, grid[r][c]);
                    if( dis[r][c] > maxForCurNode )
                    {
                        dis[r][c] = min(maxForCurNode,dis[r][c]);
                        pq.push({maxForCurNode,{r,c}});
                    }
                }
            }

        }
        return dis[n-1][n-1];
    }
};