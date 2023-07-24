class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0, time = 0;
        
        for( int i = 0; i < n; ++i )
        {
            for( int j= 0; j < m; ++j  )
            {
                if(grid[i][j] == 1 ) fresh++;
                if( grid[i][j] == 2) q.push({i,j});
            }
        }
        vector<int> delR = { 0,-1,0,1};
        vector<int> delC = { -1,0,1,0};
        vector<vector<int>> vis(n, vector<int> (m,0));
        while( !q.empty() && fresh > 0 )
        {
            int size = q.size();
            time++;
            for( int i = 0; i < size; ++i )
            {
                int row = q.front().first, col = q.front().second; q.pop();
                
                for( int del = 0; del < 4; ++del )
                {
                    int r = row + delR[del], c = col + delC[del];
                    if( r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !vis[r][c] )
                    {
                        vis[r][c] = 1;
                        q.push({r,c});
                        grid[r][c] = 2;
                        fresh--;
                        
                    }
                }
            }
        }
        if( fresh > 0 ) return -1;
        return time;
    }
};