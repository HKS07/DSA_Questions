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
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length(), l2 = text2.length();
        vector<vector<int>> dp(l1+1, vector<int> (l2+1, -1));
        return help(text1,text2, l1, l2, dp);
        
        // vector<vector<int>>> dp(l1, vector<int> (l2,0));
        
    }
};