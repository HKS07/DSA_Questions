class Solution {
public:
    int help( string &s, string &t, int i, int j, vector<vector<int>> &dp )
    {
        if( i == 0 || j == 0 ) return 0;
        
        if( dp[i][j] != -1 ) return dp[i][j];
        
        if( s[i-1] == t[j-1] ) return dp[i][j] = 1 + help( s, t, i-1,j-1, dp);
        else return dp[i][j] = 0 + max( help(s,t,i-1,j,dp), help(s,t,i,j-1,dp));
        
    }
    int longestPalindromeSubseq(string s) {
        int sl = s.length();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(sl+1, vector<int> (sl+1,-1));
        return help(s,t,sl,sl,dp);
        
    }
};