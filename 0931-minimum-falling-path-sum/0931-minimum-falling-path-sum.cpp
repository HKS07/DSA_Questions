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
        // vector<vector<int>> dp(row+1,vector<int> (col+1,INT_MAX));
        // int minn = INT_MAX;
        // for( int i = 0; i < col; ++i )
        // {
        //     minn = min(minn,help(row-1,i,matrix,dp));
        // }
        
        vector<vector<int>> dp(row, vector<int> (col,INT_MAX));
        for(int j = 0; j < col; ++j ) dp[0][j] = matrix[0][j];
        
        
                
                for( int i = 1; i < row; ++i )
                {
                    for( int j = 0; j < col; ++j )
                    {
                        int up = matrix[i][j] + dp[i-1][j];
                        int ld = INT_MAX, rd = INT_MAX;
                        if(j-1>=0) ld = matrix[i][j] + dp[i-1][j-1];
                        if(j+1<col) rd = matrix[i][j] + dp[i-1][j+1];
                        dp[i][j] = min({up,ld,rd});
                    }
                 }
               int mini = INT_MAX;
            for( auto it: dp[row-1]) mini = min(mini,it);
        return mini;
    }

};