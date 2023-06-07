class Solution {
public:
    /*int helper( string s1, string s2, int i, int j, vector<vector<int>> &dp )
    {
        //base case
        if( i < 0 || j < 0 ) return 0;
        //memoization 
        if( dp[i][j] != -1 ) return dp[i][j]; 
        // condition
        if( s1[i] == s2[j] )
            return dp[i][j] = 1 + helper( s1, s2, i - 1, j - 1, dp );
        else
            return dp[i][j] = max( helper( s1, s2, i - 1, j, dp ), helper( s1, s2, i, j - 1, dp ));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp( text1.length(), vector<int>(text2.length(), -1));
        
        return helper( text1, text2, text1.length() - 1, text2.length() - 1, dp );
    }*/
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp( n + 1, vector<int> (m + 1, -1 ));
        for( int i = 0; i <= n; ++i ) dp[i][0] = 0;
        for( int i = 0; i <= m; ++i ) dp[0][i] = 0;
        
        for( int i = 1; i <= n; ++i )
        {
            for( int j = 1; j <=m; ++j )
            {
                if( text1[i -1 ] == text2[j -1 ] ) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};