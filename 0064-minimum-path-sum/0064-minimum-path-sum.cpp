class Solution {
public:
    int help( int i , int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
         if( i == 0 && j == 0 )
         {
             return grid[0][0];
         }
        if( i < 0 || j < 0 )
            return 1e9;
        if( dp[i][j] != -1 ) return dp[i][j];
         int up, left;
         up = left = grid[i][j];
         up += help(i-1,j,grid,dp);
         left += help(i,j-1,grid,dp);
        return dp[i][j] = min( up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row, vector<int> (col,-1));
        return help(row-1,col-1,grid,dp);
    }
};