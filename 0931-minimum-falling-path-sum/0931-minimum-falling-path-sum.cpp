class Solution {
public:
    int help( int i, int j, vector<vector<int>>& m,vector<vector<int>>& dp)
    {
        if( i == 0 and j < m[0].size() and j >= 0 ) return m[i][j];
        if( j >= m[0].size() or j < 0 ) return INT_MAX;
        if(dp[i][j] != INT_MAX) return dp[i][j];
        return dp[i][j]= m[i][j] + min({help(i-1,j-1,m,dp),help(i-1,j,m,dp),help(i-1,j+1,m,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row+1,vector<int> (col+1,INT_MAX));
        int minn = INT_MAX;
        for( int i = 0; i < col; ++i )
        {
            minn = min(minn,help(row-1,i,matrix,dp));
        }
        return minn;
    }
//     int minFallingPathSumHelper(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp){
//         if(r == 0 and c < matrix[0].size() and c >= 0) return matrix[r][c]; 
//         if(c >= matrix[0].size() or c < 0) return INT_MAX;
        
//         if(dp[r][c] != INT_MAX) return dp[r][c];
//         return dp[r][c] = matrix[r][c] + min(min(minFallingPathSumHelper(matrix, r-1, c+1, dp), minFallingPathSumHelper(matrix, r-1, c, dp)), minFallingPathSumHelper(matrix, r-1, c-1, dp));
        
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int rows = matrix.size(), cols = matrix[0].size();
//         vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));
//         int ans = INT_MAX;
//         for(int c=0; c < cols; c++){
//             ans = min(ans, minFallingPathSumHelper(matrix, rows-1, c, dp));
//         }
//         return ans;
    // }
};