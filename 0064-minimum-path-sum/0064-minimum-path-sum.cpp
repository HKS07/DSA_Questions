class Solution {
public:
    int help( vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
    {
        if( i < 0 || j < 0 )
            return 1e8;
        if( i == 0 && j == 0 )
            return grid[0][0];
        if( dp[i][j] != -1 ) return dp[i][j];
        int up = grid[i][j] + help( grid, i - 1, j, dp );
        int left = grid[i][j] + help( grid, i, j - 1, dp);
        
        return dp[i][j] = min( up, left );
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row, vector<int> (col, -1));
        return help( grid, row -1, col - 1, dp );
    }
};