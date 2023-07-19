class Solution {
public:
    int helpRob( int idx, vector<int>& nums) 
    {
        if( idx == 0 ) return nums[0];
        if( idx < 0 ) return 0;
        //pick current
        int pick = nums[idx] + helpRob( idx - 2, nums );
        int notPick = helpRob(idx-1,nums);
        
        return max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        // return helpRob(nums.size()-1,nums);
        
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        
        for( int i = 1; i < nums.size(); ++i )
        {
            int pick = nums[i];
            if(i>1)
                pick+=dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick,notPick);
        }
        return *(--dp.end());
    }
};