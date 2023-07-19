class Solution {
public:
    int help( int i, int j, vector<vector<int>>& t, vector<vector<int>>& dp)
    {
        if( i == t.size()-1 )
        {
            return t[i][j];
        }
        if( i >= t.size() )
        {
            return 1e8;
        }
        if( dp[i][j] != -1 ) return dp[i][j];
        int below = t[i][j] + help(i+1,j,t,dp);
        int diagonal = t[i][j] + help(i+1,j+1,t,dp);
        
        return dp[i][j] = min(below,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n*n,-1));
        return help(0,0,triangle,dp);
    }
};