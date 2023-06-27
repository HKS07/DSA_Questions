class Solution {
public:
    int helpRob( vector<int> &nums)
    {
         vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        
        for( int hNo = 1; hNo < nums.size(); ++hNo )
        {
            int pick = nums[hNo];
            if(hNo>1)
                pick += dp[hNo-2];
            int nonPick = 0+ dp[hNo-1];
        
            dp[hNo]= max(pick, nonPick);
        }
        
        
        
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)  return nums[0];
        if( nums.size() == 2 ) return max(nums[0],nums[1]);
        vector<int> t1(nums.begin(),nums.end()-1), t2(nums.begin()+1,nums.end());
       
        return max( helpRob(t1), helpRob(t2) );
    }
};