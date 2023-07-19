class Solution {
public:
    int help( int i, int j, vector<vector<int>>& og, vector<vector<int>>& dp)
    {
        if( i >= 0 && j >= 0 && og[i][j] == 1) return 0;
        if( i == 0 && j == 0 ) return 1;
        if( i < 0 || j < 0 ) return 0;
        if( dp[i][j]  != -1 ) return dp[i][j];
        int up = 0, left = 0;
        up = help(i-1,j,og,dp);
        left = help(i,j-1,og,dp);
        
        return dp[i][j] = up+left;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int n = og.size(), m = og[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return help(n-1,m-1,og,dp);
    }
};