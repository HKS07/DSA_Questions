class Solution {
public:
    int help( int idx, int buy, int k, vector<int> &p, vector<vector<vector<int>>> &dp )
    {
        if( k == 0 ) return 0;
        if( idx == p.size() ) return 0;
        if( dp[idx][buy][k] != -1 ) return dp[idx][buy][k];
        int profit = 0;
        if( buy )
        {
            profit = max( -p[idx] + help(idx+1, !buy, k, p, dp), 0 + help(idx+1, buy, k, p, dp));
        }
        else
        {
            profit = max( p[idx] + help(idx+1, !buy, k - 1 , p, dp), 0 + help(idx+1, buy, k, p, dp));
        }
        return dp[idx][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k+1,-1)));
        return help(0,1,k,p,dp);
        
    }
};