class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        vector<vector<int>> vis( m, vector<int> (n,0));
        vector<vector<char>> sol(m, vector<char> (n,'X'));
        
        queue<pair<int,int>> q;
        
        // insert all the boundary elements
        for( int i = 0; i < m; ++i )
        {
            for( int j = 0; j < n; ++j )
            {
                if( (i==0  || j == 0 || i == m-1 || j == n-1) && board[i][j] == 'O' ) 
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                    // cout<<i<<" "<<j<<board[i][j]<<endl;
                }
            }
        }
        int delR[] = {0,-1,0,1};
        int delC[] = {-1,0,1,0};
        while( !q.empty() )
        {
            int row = q.front().first, col = q.front().second;
            q.pop();
            
            for( int del = 0; del < 4; ++del )
            {
                int r = row + delR[del], c = col + delC[del];
                if( r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'O' && !vis[r][c])
                {
                    vis[r][c] = 1;
                    q.push({r,c});
                }
            }
        }
        
        for( int i = 0; i < m; ++i )
        {
            for( int j = 0; j < n; ++j )
            {
                if( !vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};