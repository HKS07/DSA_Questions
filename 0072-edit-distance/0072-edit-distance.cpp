class Solution {
    
public:
    int help( string s1, string s2, int i, int j, vector<vector<int>> &dp )
    {
        //base case
        if( i == 0 ) return j ;
        if( j == 0 ) return i ;
        // memoize
        if( dp[i][j] != -1 ) return dp[i][j];
        // operation
        if( s1[i-1] == s2[j-1] ) return dp[i][j] = help( s1, s2, i - 1, j - 1, dp );
        
        // int ins = 1 + help( s1, s2, i, j - 1, dp), del = 1  + help( s1, s2, i - 1, j, dp ), rep = 1 + help( s1, s2, i - 1, j - 1, dp);
        return dp[i][j] = 1 + min( help( s1, s2, i, j - 1, dp), min( help( s1, s2, i - 1, j, dp ), help( s1, s2, i - 1, j - 1, dp)));
        
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.length() , len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int> ( len2 + 1, 0 ));
        
        for( int i = 0; i <= len2; ++i ) dp[0][i] = i;
        for( int i = 0; i <= len1; ++i ) dp[i][0] = i;
         
        for( int i = 1; i <= len1; ++i )
        {
            for( int j = 1; j <= len2; ++j )
            {
                if( word1[i-1] == word2[j-1] )  dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = 1 + min( dp[i][j - 1], min( dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[len1][len2];
    }
};