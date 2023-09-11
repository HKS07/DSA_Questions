class Solution {
public:
    int dp[5000][71];
    int help( int i, int sum, int target, vector<vector<int>>& mat )
    {
        if( i >= mat.size() )
        {
            return abs(sum-target);
        }
        if( dp[sum][i] != -1 ) return dp[sum][i];
        int diff = 1e9;
        
        for( int col = 0; col <mat[0].size(); ++col )
        {
            diff = min( diff, help(i+1,sum+mat[i][col], target,mat));
        }
        return dp[sum][i] = diff;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp,-1,sizeof(dp));
        return help(0,0,target,mat);
    }
};