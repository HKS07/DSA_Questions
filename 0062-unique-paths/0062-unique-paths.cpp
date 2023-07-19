class Solution {
public:
    int help( int i, int j, vector<vector<int>> &dp )
    {
        if( i == 0 && j == 0 )
        {
            return 1;
        }
        if( i < 0 || j < 0 )
        {
            return 0;
        }
        
        if( dp[i][j] != -1 ) return dp[i][j];
        int il = help( i-1, j,dp);
        int jl = help( i, j-1,dp);
        
        return dp[i][j] = il+jl;
        
    }
    int uniquePaths(int m, int n) {
        int sol = 0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return help(m-1,n-1,dp);
        // return sol;
    }
};