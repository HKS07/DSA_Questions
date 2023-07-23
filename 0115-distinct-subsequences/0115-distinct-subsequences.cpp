class Solution {
public:
    int help( int i, int j, string s, string t, vector<vector<int>> &dp )
    {
        
        if( j < 0 ) return 1;
        if( i < 0 ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        if( s[i] == t[j] ) 
        {
            // matching 
            return dp[i][j] = help(i-1,j-1,s,t,dp) + help(i-1,j,s,t,dp);
        }
        else
        {
            return dp[i][j] = help(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        int sl = s.length(), tl = t.length();
        vector<vector<int>> dp(sl, vector<int> (tl,-1));
        return help(sl-1,tl-1,s,t,dp);
    }
};