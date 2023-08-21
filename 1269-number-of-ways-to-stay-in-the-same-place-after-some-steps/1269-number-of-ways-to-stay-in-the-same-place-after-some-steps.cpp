class Solution {
public:
    int mod = 1e9+7;
    int help( int pos, int steps, int arrLen, int s, vector<vector<int>> &dp)
    {
        if( steps == 0 ) 
        {
            if( pos == 0 ) return 1;
            else return 0;
        }
        
        if( dp[pos][steps] != -1 ) return dp[pos][steps];
        
        long stay = 0 + help(pos, steps-1,arrLen,s,dp);
        long left = 0, right = 0;
        
        if( pos-1 >= 0 )
            left = help(pos-1, steps-1, arrLen,s, dp);
        if( pos+1 < arrLen && pos + 1 < (s/2)+1)
            right = help(pos+1, steps-1, arrLen,s, dp);
        
        
        return dp[pos][steps] = (stay%mod + left%mod + right%mod)%mod;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp((steps/2)+1, vector<int> (steps+1,-1));
        return help(0,steps,arrLen,steps, dp);
    }
};