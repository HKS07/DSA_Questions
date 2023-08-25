class Solution {
public:
    int dp[305][305];
    int help( int i, int j, vector<int> &n )
    {
        if( i > j ) return 0;
        
        if( dp[i][j] != -1 ) return dp[i][j];
        int sol = -1e9;
        for( int burst = i; burst <=j; ++burst )
        {
            int cost = n[i-1]*n[burst]*n[j+1] + help(i,burst-1,n) + help( burst+1,j,n);
            sol = max( sol, cost);
        }
        
        return dp[i][j] = sol;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(dp,-1,sizeof(dp));
        return help(1,nums.size()-2, nums);
    }
};