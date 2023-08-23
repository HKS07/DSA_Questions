class Solution {
public:
    int dp[102][4];
    int help( int idx, int prev, vector<int> &n )
    {
        if( idx == n.size() ) return 0;
        if(dp[idx][prev] != -1 ) return dp[idx][prev];
        int sol = 1e9;
        // already increasing order
        if( n[idx] >= prev )
        {
            //don't do anything
            int ope =  help( idx+1, n[idx],n);
            sol = min(sol, ope); 
            // do some changes
            for( int i = prev; i <= 3; ++i )
            {
                int ope = 1 + help(idx+1,i, n);
                sol = min(ope,sol);
            }
        }
        else
        {
            //descending order
            for( int i = prev; i <= 3; ++i )
            {
                int ope = 1 + help(idx+1,i,n);
                sol = min(ope,sol);
            }
        }
        return dp[idx][prev] = sol;
    }
    int minimumOperations(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return help(0,0,nums);
    }
};