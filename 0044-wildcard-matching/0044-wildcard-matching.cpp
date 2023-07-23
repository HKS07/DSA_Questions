class Solution {
public: 
    bool help( int i, int j, string s, string p, vector<vector<int>> &dp )
    {
        if( i == 0 && j == 0 ) return 1;
        if( j == 0 && i > 0 ) return 0;
        if( i == 0 && j > 0 ) 
        {
            for( int ind = 1; ind <= j; ++ind )
            {
                if( p[ind-1] != '*') return false;
            }
            return true;
        }
        
        if( dp[i][j] != -1 ) return dp[i][j];
        if( s[i-1] == p[j-1] || p[j-1] == '?' ) return dp[i][j] = help(i-1,j-1,s,p,dp);
        else if( p[j-1] == '*' ) return dp[i][j] = help(i-1,j,s,p,dp) | help(i,j-1,s,p,dp);
        else return dp[i][j]  = 0;
    }
    bool isMatch(string s, string p) {
        int sl = s.length(), pl = p.length();
        // vector<vector<int>> dp(sl+1, vector<int> (pl+1,-1));
        // return help(sl,pl,s,p,dp);
        vector<vector<int>> dp(sl+1, vector<int> (pl+1,0));
        dp[0][0] = 1;
        for(int i = 1; i <= sl; ++i ) dp[i][0] = 0;
        for(int j = 1; j <= pl && p[j-1] == '*'; ++j )
        {
            dp[0][j] = 1;
        }
        
        for( int i = 1; i <= sl; ++i )
        {
            for( int j = 1; j <= pl; ++j )
            {
                if( s[i-1] == p[j-1] || p[j-1] == '?' )  dp[i][j] = dp[i-1][j-1];
                else if( p[j-1] == '*' ) dp[i][j] = dp[i-1][j] | dp[i][j-1];
                else  dp[i][j]  = 0;
            }
        }
        return dp[sl][pl];
        
    }
};