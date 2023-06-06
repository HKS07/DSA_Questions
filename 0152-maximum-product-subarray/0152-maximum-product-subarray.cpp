class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPre = INT_MIN, maxSuf = INT_MIN;
        int pre = 1, suf = 1;
        for( int i = 0; i < nums.size(); ++i )
        {
            if( pre == 0  ) pre = 1;
            
            pre *= nums[i]; maxPre = max( maxPre, pre );
            
            if( suf == 0 ) suf = 1;
            
            suf *= nums[nums.size() -i - 1]; maxSuf = max( maxSuf, suf );
        }
//         for( int j = nums.size() - 1; j >= 0; --j )
//         {
            
//         }
        return max(maxPre,maxSuf);
    }
};