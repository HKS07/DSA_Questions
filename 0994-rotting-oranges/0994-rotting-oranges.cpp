class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0, time = 0;
        
        for( int i = 0; i < row; ++i )
        {
            for( int j= 0; j < col; ++j  )
            {
                if(grid[i][j] == 1 ) fresh++;
                if( grid[i][j] == 2) q.push({i,j});
            }
        }
        vector<vector<int>> vis(row, vector<int> (col,-1));
        while( !q.empty() && fresh > 0 )
        {
            int size = q.size();
            time++;
            for( int i = 0; i < size; ++i )
            {
                int r = q.front().first, c = q.front().second; q.pop();
                
                //up
                if( r - 1 >= 0 && grid[r-1][c] == 1 && vis[r-1][c] == -1 )
                {
                    vis[r-1][c] = 1;
                    q.push({r-1,c});
                    fresh--;
                }
                //down
                if( r + 1 < row && grid[r + 1][c] == 1 && vis[r + 1][c] == -1 )
                {
                    vis[r + 1][c] = 1;
                    q.push({r + 1,c});
                    fresh--;
                }
                //left
                if( c - 1 >= 0 && grid[r][c-1] == 1 && vis[r][c-1] == -1 )
                {
                    vis[r][c-1] = 1;
                    q.push({r,c-1});
                    fresh--;
                }
                //right
                if( c + 1 < col && grid[r][c+1] == 1 && vis[r][c+1] == -1 )
                {
                    vis[r][c+1] = 1;
                    q.push({r,c+1});
                    fresh--;
                }
            }
        }
        if( fresh > 0 ) return -1;
        return time;
    }
};