class Solution {
    
public:
    int help( string s1, string s2, int i, int j, vector<vector<int>> &dp )
    {
        //base case
        if( i < 0 ) return j + 1;
        if( j < 0 ) return i + 1;
        // memoize
        if( dp[i][j] != -1 ) return dp[i][j];
        // operation
        if( s1[i] == s2[j] ) return dp[i][j] = help( s1, s2, i - 1, j - 1, dp );
        
        int ins = 1 + help( s1, s2, i, j - 1, dp), del = 1  + help( s1, s2, i - 1, j, dp ), rep = 1 + help( s1, s2, i - 1, j - 1, dp);
        return dp[i][j] = min( ins, min( del, rep));
        
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.length() - 1, len2 = word2.length() -1;
        vector<vector<int>> dp(len1 + 1, vector<int> ( len2 + 1, -1 ));
        return help( word1, word2, len1, len2, dp );
    }
};