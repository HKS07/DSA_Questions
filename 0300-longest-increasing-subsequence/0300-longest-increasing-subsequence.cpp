class Solution {
public:
    int lenHelp( int idx, int prevIdx, vector<int> &nums, int n, vector<vector<int> > &dp )
    {
        if( idx == n ) return 0;
        
        if( dp[idx][prevIdx + 1] != -1 ) return dp[idx][prevIdx+1];
        
        int len = lenHelp( idx +1 , prevIdx, nums, n, dp);
        
        if( prevIdx == -1 || nums[idx] > nums[prevIdx] )
            len = max( len, 1 + lenHelp( idx + 1, idx, nums, n, dp));
            
        return dp[idx][prevIdx+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int> > dp( nums.size(), vector<int>( nums.size() + 1, -1 ));
        
        return lenHelp( 0, -1, nums, nums.size(), dp );
    }
};