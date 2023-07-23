class Solution {
public:
    int help( string &s1, string &s2, int i, int j, vector<vector<int>> &dp )
    {
        if( i == 0 || j == 0 ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        
        if( s1[i-1] == s2[j-1] ) return dp[i][j] = 1 + help(s1,s2, i-1,j-1,dp);
        else
        {
            return dp[i][j] = 0 + max(help( s1, s2, i-1,j,dp),help( s1, s2, i, j - 1,dp)) ;
        }
        
        
    }
    int longestCommonSubsequence(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        // vector<vector<int>> dp(l1+1, vector<int> (l2+1, -1));
        // return help(text1,text2, l1, l2, dp);
        
        vector<vector<int>> dp(l1+1, vector<int> (l2+1,-1));
        for( int j = 0; j <= l2; ++j ) dp[0][j]  = 0;
        for( int i = 0; i <= l1; ++i ) dp[i][0]  = 0;
        
        for( int i = 1; i <= l1; ++i )
        {
            for( int j = 1; j <= l2; ++j )
            {
                if( s1[i-1] == s2[j-1] )  dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = dp[i][j] = 0 + max(dp[i-1][j],dp[i][j - 1]) ;
            }
        }
        return dp[l1][l2];
    }
};