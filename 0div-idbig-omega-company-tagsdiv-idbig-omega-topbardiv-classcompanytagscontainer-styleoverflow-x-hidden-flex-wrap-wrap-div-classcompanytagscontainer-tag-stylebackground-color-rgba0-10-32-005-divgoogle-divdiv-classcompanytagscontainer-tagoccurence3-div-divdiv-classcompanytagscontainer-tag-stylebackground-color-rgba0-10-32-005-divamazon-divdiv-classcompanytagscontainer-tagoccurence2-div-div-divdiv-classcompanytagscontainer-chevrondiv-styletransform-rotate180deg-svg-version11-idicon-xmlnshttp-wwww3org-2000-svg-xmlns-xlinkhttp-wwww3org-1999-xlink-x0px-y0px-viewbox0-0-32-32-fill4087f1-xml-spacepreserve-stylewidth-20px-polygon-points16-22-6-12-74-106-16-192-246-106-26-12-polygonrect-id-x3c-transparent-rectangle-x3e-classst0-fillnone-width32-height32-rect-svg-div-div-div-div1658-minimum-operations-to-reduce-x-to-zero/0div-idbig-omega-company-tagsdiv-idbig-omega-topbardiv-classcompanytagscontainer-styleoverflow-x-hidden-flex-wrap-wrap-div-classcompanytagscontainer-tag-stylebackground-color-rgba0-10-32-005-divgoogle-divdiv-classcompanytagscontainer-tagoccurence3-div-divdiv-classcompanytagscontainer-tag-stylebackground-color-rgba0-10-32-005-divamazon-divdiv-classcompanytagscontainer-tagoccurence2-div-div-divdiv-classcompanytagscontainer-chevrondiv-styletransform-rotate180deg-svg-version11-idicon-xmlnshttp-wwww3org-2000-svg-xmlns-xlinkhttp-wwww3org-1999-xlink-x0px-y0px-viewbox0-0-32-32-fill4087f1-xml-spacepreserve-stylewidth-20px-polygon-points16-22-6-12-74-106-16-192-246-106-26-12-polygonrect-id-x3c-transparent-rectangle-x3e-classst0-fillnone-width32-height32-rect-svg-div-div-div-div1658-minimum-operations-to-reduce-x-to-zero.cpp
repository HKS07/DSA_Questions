class Solution {
public:
    // int dp[100001][100001];
    // int help( int l, int r, int sum, vector<int>& n, vector<vector<int>> &dp )
//     {
//         if( sum == 0 ) return 0;
//         if( l > r ) return sum == 0? 0: 1e8;
//         if( l == n.size() ) return sum == 0? 0:1e8;
//         if( r < 0 ) return sum == 0? 0:1e8;
        
//         if( dp[l][r] != -1 ) return dp[l][r];
        
//         //reduce left
//          int left =  1 + help(l+1,r, sum-n[l],n,dp);
//         //reduce right
//          int right = 1 + help(l,r-1,sum-n[r],n,dp);
        
//         return dp[l][r] = min(left,right);
//     }
//     int minOperations(vector<int>& nums, int x) {
//         // memset(dp,-1,sizeof(dp));
//         int n = nums.size();
//         // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
//         // long long sol =  help(0,nums.size()-1,x,nums,dp);
//         // return sol>=1e8?-1:sol;
        
        
//     }
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size(), l = 0, r = 0, curSum = 0, len = -1;
        for( auto i:nums) sum+= i;
        for( l = 0, r = 0; r < n; ++r )
        {
            curSum += nums[r];
            while( l <= r && curSum > sum - x )
            {
                curSum -= nums[l++];
            }
            if( curSum == sum - x ) len = max( len, r-l+1);
        }
        return len == -1 ? -1: n - len;
    }
};