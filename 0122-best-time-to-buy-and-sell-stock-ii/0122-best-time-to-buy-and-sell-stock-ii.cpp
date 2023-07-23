class Solution {
public:
    int help( int i, int buy, vector<int>& prices, vector<vector<int>> &dp)
    {
        if( i == prices.size() ) return 0;
        if( dp[i][buy] != -1 ) return dp[i][buy];
        int profit = 0;
        if( buy )
        {
            profit = max(-prices[i] + help(i+1,0,prices,dp),help(i+1,1,prices,dp)); 
        }
        else
        {
            profit = max( prices[i] + help(i+1,1,prices,dp), help(i+1,0,prices,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2,-1));
        return help(0,1,prices,dp);
    }
};