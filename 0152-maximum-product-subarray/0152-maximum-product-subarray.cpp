class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPre = INT_MIN, maxSuf = INT_MIN;
        int pre = 1, suf = 1;
        for( int i = 0; i < nums.size(); ++i )
        {
            if( pre == 0  ) pre = 1;
            
            pre *= nums[i]; maxPre = max( maxPre, pre );
        }
        for( int j = nums.size() - 1; j >= 0; --j )
        {
            if( suf == 0 ) suf = 1;
            
            suf *= nums[j]; maxSuf = max( maxSuf, suf );
        }
        return max(maxPre,maxSuf);
    }
};