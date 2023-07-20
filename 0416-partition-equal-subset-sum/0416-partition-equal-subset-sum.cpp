class Solution {
public:
    bool help( int ind, int t, vector<int>& n, vector<vector<int>> &dp)
    {
        if( t == 0 ) return true;
        if( ind == 0 ) return n[ind] == t;
        if( dp[ind][t] != -1 ) return dp[ind][t];
        bool notPick = help(ind-1,t,n,dp);
        bool pick = false;
        if( n[ind] <= t ) pick = help(ind-1,t-n[ind],n,dp);
        
        return dp[ind][t] = pick | notPick;
    }
    bool canPartition(vector<int>& nums) {
        int s = nums.size();
        int t=0;
        for( auto i:nums) t += i;
        if( t % 2 == 1 ) return false;
        vector<vector<int>> dp(s+1, vector<int> (t/2+1,-1));
        return help(s-1,t/2,nums,dp);
    }
};