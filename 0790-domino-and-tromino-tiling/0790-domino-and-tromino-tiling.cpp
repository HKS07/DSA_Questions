class Solution {
public:
    int dp[1001][3];
    int mod = 1e9+7;
    int help( int n, int state )
    {
         
        if( n == 0 ) {
            return state == 0? 1:0;
        }
        if( n < 0 ) return 0;
        
        if( dp[n][state] != -1) return dp[n][state];
        //state 0
        int totS = 0;
        if( state == 0)
        {
            totS = ((help(n-1,state)%mod + help(n-2,state)%mod)%mod + (help(n-1,1)%mod + help(n-1,2)%mod)%mod)%mod;
            
        }
        else if( state == 1 )
        {
            totS = (help(n-1,state)%mod + help(n-2,0)%mod)%mod;
            
        }
        else
        {
            totS = (help(n-1,state)%mod + help(n-2,0)%mod)%mod;
            
        }
        return dp[n][state] = totS;
    }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return help(n,0);
    }
};